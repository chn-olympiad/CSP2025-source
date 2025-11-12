#include <bits/stdc++.h>

using namespace std;

namespace FastRead{
    char buf[1 << 20 | 5], *s = buf, *t = buf;
    #define gc() (s == t && (t = (s = buf) + fread(buf, 1, 1 << 20, stdin), s == t) ? EOF : *s ++ )
    template <typename T>
    inline void Read(T &x)
    {
        char ch = gc();
        int f = 0;
        x = 0;
        while(ch < '0' || ch > '9') f = ch == '-', ch = gc();
        while('0' <= ch && ch <= '9') x = x * 10 + (ch ^ 48), ch = gc();
        f && (x = -x);
    }
    inline void Read(char *str)
    {
        while((*str = gc()) <= 32 || *str >= 127) ;
        str ++ ;
        while((*str = gc()) > 32 && *str < 127) str ++ ;
        *str = 0;
    }
}
using FastRead::Read;

typedef long long LL;

const int N = 1e4 + 15, M = 1e6 + 5;

int n, m, k;
int c[N];
struct Edge{
    int u, v, w, t;
    bool operator < (const Edge &p) const
    {
        return w < p.w;
    }
}e[M];
int fa[N];

inline int gfa(int i)
{
    return i == fa[i] ? i : fa[i] = gfa(fa[i]);
}
inline LL Kruskal(int s)
{
    for(int i = 1; i <= n + k; i ++ ) fa[i] = i;
    int m0 = 0;
    LL sum = 0;
    for(int i = 1; i <= k; i ++ ) sum += (s >> i & 1) * c[i];
    for(int i = 1; i <= m; i ++ )
    {
        if(!(s >> e[i].t & 1)) continue;
        int x = gfa(e[i].u), y = gfa(e[i].v);
        if(x != y)
        {
            sum += e[i].w;
            fa[x] = y;
            if(s == 1) e[ ++ m0] = e[i];
        }
    }
    if(s == 1) m = m0;
    return sum;
}

int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);

    Read(n), Read(m), Read(k);
    for(int i = 1; i <= m; i ++ )
    {
        Read(e[i].u), Read(e[i].v), Read(e[i].w);
    }
    sort(e + 1, e + m + 1);
    LL ans = Kruskal(1);
    for(int i = 1; i <= k; i ++ )
    {
        Read(c[i]);
        for(int j = 1; j <= n; j ++ )
        {
            e[ ++ m] = {n + i, j, 0, i};
            Read(e[m].w);
        }
    }
    sort(e + 1, e + m + 1);
    for(int i = 1; i < 1 << k; i ++ ) ans = min(ans, Kruskal(i << 1 | 1));
    printf("%lld\n", ans);
    return 0;
}