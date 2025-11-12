#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e4 + 15;
struct node
{
    int u, v, w;
    node() {}
    node(const int &U, const int &V, const int &W) : u(U), v(V), w(W) {}
    inline bool operator<(const node &o) const { return w < o.w; }
};
vector<node> e, g;
int n, m, k, fa[MAXN], c[15], a[15][MAXN];
inline int find(const int &x)
{
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i)
        fa[i] = i;
    do
    {
        int u, v, w;
        for (int i = 0; i < m; ++i)
        {
            cin >> u >> v >> w;
            e.emplace_back(u, v, w);
        }
    } while (0);
    for (int i = 1; i <= k; ++i)
    {
        cin >> c[i];
        for (int j = 1; j <= n; ++j)
            cin >> a[i][j];
    }
    sort(e.begin(), e.end());
    long long ans = 0;
    for (int i = 0; i < m; ++i)
    {
        int r1 = find(e[i].u), r2 = find(e[i].v);
        if (r1 != r2)
        {
            g.emplace_back(e[i]);
            fa[r1] = r2;
            ans += e[i].w;
        }
    }
    int S = (1 << k);
    for (int s = 1; s < S; ++s)
    {
        vector<node> tmp(g);
        long long res = 0;
        for (int i = 1; i <= k; ++i)
            if (s & (1 << (i - 1)))
            {
                res += c[i];
                for (int j = 1; j <= n; ++j)
                    tmp.emplace_back(j, n + i, a[i][j]);
            }
        sort(tmp.begin(), tmp.end());
        for (int i = 1; i <= n + 10; ++i)
            fa[i] = i;
        int cnt = 0, limit = n + __builtin_popcount(s) - 1;
        for (const auto &i : tmp)
        {
            int u = find(i.u), v = find(i.v);
            if (u != v)
            {
                res += i.w;
                fa[v] = u;
                if (++cnt == limit)
                    break;
            }
        }
        if (res < ans)
            ans = res;
    }
    cout << ans << '\n';
    return 0;
}