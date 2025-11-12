#include <cstdio>
#include <cstdint>
#include <cstring>
#include <array>
#include <vector>
#include <tuple>
#include <algorithm>

#define wzc(x) freopen(x".in", "r", stdin), freopen(x".out", "w", stdout)

using i32 = int32_t;
using u32 = uint32_t;
using i64 = int64_t;
using u64 = uint64_t;

const int K = 16, N = 1e4 + 32, M = 1e6 + 1e5 + 32;

struct edge
{
    i64 u, v, w, next;
};

inline bool operator<(const edge& x, const edge& y)
{
    return x.w < y.w;
}

int dsu[N];
bool vis[2 * M];

inline void init()
{
    for (int i = 0; i < N; i++) dsu[i] = i;
}

int rep(int x)
{
    if (dsu[x] == x) return x;
    return dsu[x] = rep(dsu[x]);
}

inline void merge(int x, int y)
{
    x = rep(x); y = rep(y);
    dsu[x] = y;
}

inline bool allow(int n, int mask, int u)
{
    if (u <= n) return true;
    else return 1 & (mask >> (u - n - 1));
}

struct graph
{
    edge e[2 * M];
    int head[N], cnt;

    graph()
    {
        memset(head, -1, sizeof head); cnt = 0;
    }

    inline void add(int u, int v, i64 w)
    {
        e[cnt] = (edge) {u, v, w, head[u]};
        head[u] = cnt;
        cnt++;
    }

    inline i64 kruskal(int n, int mask)
    {
        std::sort(e, e + cnt);
        init();
        i64 ans = 0;
        for (int i = 0; i < cnt; i++)
        {
            auto [u, v, w, next] = e[i];
            if (!allow(n, mask, u) || !allow(n, mask, v)) continue;
            if (rep(u) == rep(v)) continue;
            merge(u, v);
            ans += w;
            vis[i] = true;
        }
        return ans;
    }
} G, G2;

i64 c[K], a[K][N];

int main()
{
    wzc("road");
    int n, m, k; scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < m; i++)
    {
        int u, v, w; scanf("%d %d %d", &u, &v, &w);
        G.add(u, v, w);
        G.add(v, u, w);
    }
    for (int j = 1; j <= k; j++)
    {
        scanf("%lld", &c[j]);
        for (int i = 1; i <= n; i++)
            scanf("%lld", &a[j][i]);
    }

    G.kruskal(n, 1023);
    for (int i = 0; i < G.cnt; i++)
        if (vis[i])
        {
            auto [u, v, w, next] = G.e[i];
            G2.add(u, v, w);
            G2.add(v, u, w);
        }
    for (int j = 1; j <= k; j++)
        for (int i = 1; i <= n; i++)
        {
            int u = i, v = n + j;
            i64 w = a[j][i];
            G2.add(u, v, w);
            G2.add(v, u, w);
        }

    i64 ans = 1e18;
    for (int mask = 0; mask < (1 << k); mask++)
    {
        i64 ans1 = 0;
        for (int j = 1; j <= k; j++)
            if (1 & (mask >> (j - 1)))
                ans1 += c[j];
        ans1 += G2.kruskal(n, mask);
        ans = std::min(ans, ans1);
    }
    printf("%lld\n", ans);
}