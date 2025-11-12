#include <algorithm>
#include <cctype>
#include <cstdio>
#define MAXN 10013
#define MAXM 1100013
using namespace std;
using lli = long long;

namespace IO
{
#define SIZ (1 << 18)
    char ibuf[SIZ], *p1 = nullptr, *p2 = nullptr;
#define gc() (p1 == p2 && (p2 = (p1 = ibuf) + fread(ibuf, 1, SIZ, stdin), p1 == p2) ? EOF : *p1++)
    void rd(int &x)
    {
        x = 0;
        char c = gc();
        while (!isdigit(c))
            c = gc();
        while (isdigit(c))
            x = x * 10 + (c ^ 48), c = gc();
    }
    template <typename... Arg>
    inline void rd(int &x, Arg &...args)
    {
        rd(x), rd(args...);
    }
#undef SIZ
#undef gc
}
using IO::rd;

struct Edge
{
    int u, v, w;
    bool operator<(const Edge &other) const
    {
        return w < other.w;
    }
} edges[1000003], tmpie[110003];
int fa[MAXN], a[11][MAXN];

int getfa(const int &x)
{
    return !fa[x] ? x : fa[x] = getfa(fa[x]);
}
inline bool mergest(int x, int y)
{
    x = getfa(x), y = getfa(y);
    if (x == y)
        return false;
    fa[y] = x;
    return true;
}

int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    int n, m, k;
    rd(n, m, k);
    for (int i = 1; i <= m; ++i)
        rd(edges[i].u, edges[i].v, edges[i].w);
    sort(edges + 1, edges + m + 1);
    lli ans = 0;
    int tot = 0;
    for (int i = 1; i <= m && tot != n - 1; ++i)
        if (mergest(edges[i].u, edges[i].v))
            ans += edges[i].w, edges[++tot] = edges[i];
    for (int i = 0; i < k; ++i)
        for (int j = 0; j <= n; ++j)
            rd(a[i][j]);
    int etot = 0;
    lli curw;
    for (int sta = 1, tmp, cur; sta < (1 << k); ++sta)
    {
        tmp = sta;
        copy(edges + 1, edges + n, tmpie + 1), etot = n - 1, curw = 0;
        while (tmp)
        {
            cur = __builtin_ctz(tmp);
            curw += a[cur][0];
            for (int i = 1; i <= n; ++i)
                tmpie[++etot] = {n + cur + 1, i, a[cur][i]};
            tmp ^= 1 << cur;
        }
        sort(tmpie + 1, tmpie + etot + 1);
        fill(fa + 1, fa + n + k + 1, 0);
        tot = 0, tmp = __builtin_popcount(sta) + n - 1;
        for (int i = 1; i <= etot && tot != tmp; ++i)
            if (mergest(tmpie[i].u, tmpie[i].v))
                curw += tmpie[i].w, ++tot;
        ans = min(ans, curw);
    }
    printf("%lld", ans);
    return 0;
}
