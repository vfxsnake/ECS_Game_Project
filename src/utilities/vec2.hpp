#pragma once

#include <SFML/Graphics.hpp>
#include <cmath>
#include <stdexcept>
#include <limits>


template <typename T>
class Vec2 
{
public:
    T x, y;

    constexpr Vec2(T xIn=0, T yIn=0) : x(xIn), y(yIn) { }

    // constructor to convert from sf::Vector2
    Vec2(const sf::Vector2<T>& vec): x(vec.x), y(vec.y) { }

    // allow automatic conversion to sf::Vector2
    // this lets us pass our Vec2 into sfml functions
    operator sf::Vector2<T>()
    {
        return sf::Vector2<T>(x, y);
    }

    inline Vec2 operator + (const Vec2& rhs) const
    {
        return Vec2(x+rhs.x, y+rhs.y);
    }

    inline Vec2 operator - (const Vec2& rhs) const
    {
        return Vec2(x-rhs.x, y-rhs.y);
    }

    inline Vec2 operator / (const T val) const
    {
        if (val == 0)
        {
            throw std::runtime_error("Division by zero in Vec2");
        }

        return Vec2(x/val, y/val);
    }

    inline Vec2 operator * (const T val) const
    {
        return Vec2(x*val, y*val);
    }

    inline bool operator == (const Vec2& rhs) const
    {
        if (x == rhs.x && y == rhs.y)
        {
            return true;
        }

        return false;
    }

    inline bool operator != (const Vec2& rhs) const
    {

        return !(*this==rhs);
    }

    inline void operator += (const Vec2& rhs)
    {
        x += rhs.x;
        y += rhs.y;
    }

    inline void operator -= (const Vec2& rhs)
    {
        x -= rhs.x;
        y -= rhs.y;
    }

    inline void operator *= (const T val)
    {
        x *= val;
        y *= val;
    }

    inline void operator /= (const T val)
    {
        if (val == 0)
        {
            throw std::runtime_error("Division by zero in Vec2");
        }
        x /= val;
        y /= val;
    }

    inline float distance(const Vec2& rhs) const
    {
        Vec2 delta = rhs - *this;
        return magnitude(delta);
    }

    constexpr float magnitude() const
    {
        return sqrt((x*x) + (y*y));
    }

    constexpr Vec2 normalize() const
    {
        float mag = magnitude();
        if (mag == std::numeric_limits<float>::epsilon())
        {
            return Vec2(0, 0);
        }
        return Vec2(x / mag, y / mag);
    }

    constexpr float dot(const Vec2& v) const
    {
        return x * v.x + y * v.y;
    }
};

// similar to macros, using creates a type def alias.
using Vec2f = Vec2<float>;
using Vec2i = Vec2<int>;