#include <bits/stdc++.h>
#define int long long
#define PII std::pair<int,int>
#define all(v) v.begin(),v.end()
#define fro(i,a,b) for (int i = a; i <= b; i++)
using namespace std;
namespace FastIO
{
    char buf[1 << 22] , *p1 = buf , *p2 = buf;
    #define Getchar ((p1 == p2 && (p2 = (p1 = buf) + \
        fread (buf , 1 , 1 << 21 , stdin) , p1 == p2)) ? EOF : *p1++)
    inline int read ()
    {
        int x = 0 , f = 1; char c = Getchar;
        while (!isdigit (c)) { if (c == '-') f = -1; c = Getchar; }
        while (isdigit (c)) { x = x * 10 + (c ^ 48); c = Getchar; }
        return x * f;
    }
};
using FastIO :: read;
const int N = 1e5 + 5;

int n , res ; 
struct node { int a , b , c; } a[N];
std :: priority_queue < PII > q1 , q2 , q3;

inline void FakeMain ()
{
    res = 0;
    while (q1.size ()) q1.pop ();
    while (q2.size ()) q2.pop ();
    while (q3.size ()) q3.pop ();
    n = read ();
    fro (i , 1 , n) a[i].a = read () , a[i].b = read () , a[i].c = read ();
    fro (i , 1 , n)
    {
        int x = std :: max ({a[i].a , a[i].b , a[i].c});
        res += x;
        if (x == a[i].a)
        {
            int w1 = a[i].b - a[i].a , w2 = a[i].c - a[i].a;
            if (w1 < w2) q1.push ({w2 , 3});
            else q1.push ({w1 , 2});
        }
        else if (x == a[i].b)
        {
            int w1 = a[i].a - a[i].b , w2 = a[i].c - a[i].b;
            if (w1 < w2) q2.push ({w2 , 3});
            else q2.push ({w1 , 1});
        }
        else if (x == a[i].c)
        {
            int w1 = a[i].a - a[i].c , w2 = a[i].b - a[i].c;
            if (w1 < w2) q3.push ({w2 , 2});
            else q3.push ({w1 , 1});
        }
    }
    while (q1.size () > n / 2) res += q1.top ().first , q1.pop ();
    while (q2.size () > n / 2) res += q2.top ().first , q2.pop ();
    while (q3.size () > n / 2) res += q3.top ().first , q3.pop ();
    std :: cout << res << "\n";
}

signed main ()
{
    freopen ("club.in" , "r" , stdin);
    freopen ("club.out" , "w" , stdout);
    for (int T = read (); T --; FakeMain ());
    return 0;
}