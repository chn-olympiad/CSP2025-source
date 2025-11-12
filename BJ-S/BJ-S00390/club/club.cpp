#include <bits/stdc++.h>

typedef long long i64;

constexpr i64 MAXN = 1e5 + 10;

i64 a[MAXN][4], n;
i64 v[MAXN][4];
i64 p[MAXN], si;

bool cmp1(i64 lhs, i64 rhs)
{
    assert(si);
    return a[si][lhs] > a[si][rhs];
}

bool cmp(i64 lhs, i64 rhs)
{
    i64 lw = a[lhs][v[lhs][1]] - a[lhs][v[lhs][2]];
    i64 rw = a[rhs][v[rhs][1]] - a[rhs][v[rhs][2]];
    return lw > rw;
}

i64 cnt[4];

void solve()
{
    std::cin >> n;
    for (i64 i = 1; i <= n; ++i) std::cin >> a[i][1] >> a[i][2] >> a[i][3];
    for (i64 i = 1; i <= n; ++i)
    {
        for (i64 j = 1; j <= 3; ++j) v[i][j] = j;
        si = i, std::sort(v[i] + 1, v[i] + 4, cmp1), si = 0;
    }
    for (i64 i = 1; i <= n; ++i) p[i] = i;
    std::sort(p + 1, p + 1 + n, cmp);

    i64 tot = cnt[1] = cnt[2] = cnt[3] = 0;
    for (i64 i = 1; i <= n; ++i)
    {
        i64 u = p[i];
        for (i64 j = 1; j <= 3; ++j)
        {
            if (cnt[v[u][j]] + 1 <= n / 2)
            {
                tot += a[u][v[u][j]];
                ++cnt[v[u][j]];
                break;
            }
        }
    }
    std::cout << tot << '\n';
}

signed main()
{
    freopen("club.out", "w", stdout);
    freopen("club.in", "r", stdin);
    i64 T;
    std::cin >> T;
    while (T--) solve();
    return 0;
}
