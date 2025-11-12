#include <bits/stdc++.h>
#define int long long
#define PII std::pair<int,int>
#define all(v) v.begin(),v.end()
#define fro(i,a,b) for (int i = a; i <= b; i++)
using namespace std;
inline void chkmin (int& x , int y) { (x > y) && (x = y); }
inline void chkmax (int& x , int y) { (x < y) && (x = y); }
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
const int N = 1e4 + 15 , M = 1e6 + 5;

int n , m , k , tot , res , ans;
struct node { int u , v , w; } a[M] , b[M] , d[M];
int c[N] , w[11][N] , p[11][N] , fa[N] , s[N];
int t[N * 10];
PII tmp[N];

inline int Find (int x) { return x == fa[x] ? x : fa[x] = Find (fa[x]); }
inline void Union (int x , int y)
{
    x = Find (x) , y = Find (y);
    if (s[x] > s[y]) x ^= y ^= x ^= y;
    fa[x] = y , s[y] += s[x];
}

signed main ()
{
    freopen ("road.in" , "r" , stdin);
    freopen ("road.out" , "w" , stdout);
    n = read () , m = read () , k = read ();
    fro (i , 1 , n) fa[i] = i , s[i] = 1;
    fro (i , 1 , m)
    {
        int u = read () , v = read () , w = read ();
        a[i] = {u , v , w};
    }
    fro (i , 1 , k)
    {
        c[i] = read ();
        fro (j , 1 , n) w[i][j] = read () ;
    }
    std :: sort (a + 1 , a + m + 1 , [] (node x , node y) {
        return x.w < y.w ;
    });
    fro (i , 1 , m)
    {
        int u = a[i].u , v = a[i].v , w = a[i].w;
        if (Find (u) == Find (v)) continue;
        Union (u , v); tot++; a[tot] = a[i]; ans += w;
        if (tot == n - 1) break;
    }
    for (int S = 1; S < (1 << k); S++)
    {
        int cit = 0;
        res = 0;
        fro (i , 1 , n + k) b[i].w = 1e9 , fa[i] = i , s[i] = 1;
        for (int i = 0; i < k; i++) if (S >> i & 1)
        {
            fro (j , 1 , n) if (b[j].w > w[i + 1][j])
                b[j].w = w[i + 1][j] , b[j].u = j , b[j].v = n + i + 1;
            res += c[i + 1] , cit++;
        }
        std :: sort (b + 1 , b + n + 1 , [] (node x , node y) {
            return x.w < y.w ;
        });
        std :: merge (a + 1 , a + tot + 1 , b + 1 , b + n + 1 , d + 1 , 
            [] (node x , node y) { return x.w < y.w; });
        int cnt = 0;
        fro (i , 1 , tot + n)
        {
            int u = d[i].u , v = d[i].v , w = d[i].w;
            if (Find (u) == Find (v)) continue;
            // cerr << u << " " << v << " " << w << "\n";
            Union (u , v); cnt++; res += w;
            if (cnt == n + cit - 1) break;
        }
        chkmin (ans , res);
    }
    std :: cout << ans ;
    return 0;
}