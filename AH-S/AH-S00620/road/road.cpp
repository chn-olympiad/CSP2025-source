#include <iostream>
#include <algorithm>
#include <limits>
#include <numeric>
#include <cstdio>
#include <cctype>

using namespace std;

using ll = long long;
constexpr int maxn = 10000, maxm = 1000000, maxk = 10;
int c[maxk + 5], fa[maxn + maxk + 5];

struct edge_t
{
    int u, v, w, id;
} e[maxm + 5];

int read()
{
    char ch;
    while ((ch = getchar()) && !isdigit(ch));
    int ans = ch - '0';
    while ((ch = getchar()) && isdigit(ch))
        ans = ans * 10 + ch - '0';
    return ans;
}

int get(int x)
{
    if (x == fa[x])
        return x;
    return fa[x] = get(fa[x]);
}

int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);

    int n = read(), m = read(), k = read();
    for (int i = 1; i <= m; i++)
    { e[i].u = read(); e[i].v = read(); e[i].w = read(); }

    iota(fa + 1, fa + n + 1, 1);
    sort(e + 1, e + m + 1, [](const edge_t& x, const edge_t& y) { return x.w < y.w; });
    for (int i = 1, j = 1; i <= m; i++)
    {
        int fu = get(e[i].u), fv = get(e[i].v);
        if (fu != fv)
        {
            fa[fu] = fv;
            e[j++] = e[i];
        }
    }

    for (int i = 1; i <= k; i++)
    {
        c[i] = read();
        for (int j = 1; j <= n; j++)
            e[i * n + j - 1] = {j, i + n, read(), i};
    }
    
    int tot = n - 1 + k * n;
    sort(e + 1, e + tot + 1, [](const edge_t& x, const edge_t& y) { return x.w < y.w; });

    ll ans = numeric_limits<ll>::max();
    for (int s = 0; s < 1 << k; s++)
    {
        ll cur = 0;
        iota(fa + 1, fa + n + k + 1, 1);
        for (int i = 1; i <= k; i++)
            if (s >> (i - 1) & 1)
                cur += c[i];

        int c = 0, popc = __builtin_popcount(s);
        for (int i = 1; i <= tot && c < n + popc && cur < ans; i++)
            if (0 == e[i].id || (s >> (e[i].id - 1) & 1))
            {
                int fu = get(e[i].u), fv = get(e[i].v);
                if (fu != fv)
                {
                    fa[fu] = fv;
                    c++;
                    cur += e[i].w;
                }
            }
        ans = min(ans, cur);
    }
    cout << ans << endl;

    return 0;
}