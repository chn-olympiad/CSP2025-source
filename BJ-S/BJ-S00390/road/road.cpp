#include <bits/stdc++.h>

typedef long long i64;

constexpr i64 MAXN = 2e4 + 10;
constexpr i64 MAXM = 2e6 + 10;

struct megp
{
    i64 u, v, w;
} E[MAXM];

bool cmp(const megp &lhs, const megp &rhs)
{
    return lhs.w < rhs.w;
}

i64 fa[MAXN];
i64 ufind(i64 x)
{
    if (fa[x] == x) return x;
    else return fa[x] = ufind(fa[x]);
}

i64 c[20], a[20][MAXN], n, m, k;

void solve()
{
    std::sort(E + 1, E + 1 + m, cmp);
    for (i64 i = 1; i <= n; ++i) fa[i] = i;
    i64 tot = 0;
    for (megp e: E)
    {
        if (ufind(e.u) == ufind(e.v)) continue;
        //std::cout << ufind(e.u) << ' ' << ufind(e.v) << '\n';
        //for (i64 i = 1; i <= n; ++i) std::cout << ufind(i) << ' ';
        //puts("");
        tot += e.w;
        fa[ufind(e.u)] = ufind(e.v);
    }
    //for (i64 i = 1; i <= n; ++i) std::cout << ufind(i) << ' ';
    //puts("");
    std::cout << tot << '\n';
}

void subtaskA()
{
    for (i64 j = 1; j <= k; ++j)
    {
        assert(c[j] == 0);
        i64 p = 0;
        for (i64 i = 1; i <= n; ++i)
            if (a[j][i] == 0) p = i;
        assert(p);
        for (i64 i = 1; i <= n; ++i)
            E[++m] = {p, i, a[j][i]};
    }
    solve();
}
bool isSubA()
{
    for (i64 j = 1; j <= k; ++j)
    {
        i64 cnt = 0;
        if (c[j] != 0) return 0;
        for (i64 i = 1; i <= n; ++i) if (a[j][i] == 0) ++cnt;
        if (!cnt) return 0;
    }
    return 1;
}

signed main()
{
    freopen("road.out", "w", stdout);
    freopen("road.in", "r", stdin);
    std::cin >> n >> m >> k;
    for (i64 i = 1; i <= m; ++i)
    {
        i64 u, v, w;
        std::cin >> u >> v >> w;
        E[i] = {u, v, w};
    }
    for (i64 j = 1; j <= k; ++j)
    {
        std::cin >> c[j];
        for (i64 i = 1; i <= n; ++i)
        {
            std::cin >> a[j][i];
        }
    }
    if (isSubA()) subtaskA();
    else solve();
    return 0;
}
