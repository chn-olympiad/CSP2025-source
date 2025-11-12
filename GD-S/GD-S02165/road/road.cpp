#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e4 + 15, M = 1e6 + 15, K = 12;
struct Edge{
    int u, v, w;
}edge[M];
vector <Edge> nedge;
int c[K], a[K][N], n, m, k, f[N], ans;
void init(int n)
{
    for (int i = 0; i <= n; i ++)
        f[i] = i;
}
int getf(int p)
{
    return f[p] == p ? p : f[p] = getf(f[p]);
}
bool cmp(Edge a, Edge b)
{
    return a.w < b.w;
}
signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i ++)
    {
        cin >> edge[i].u >> edge[i].v >> edge[i].w;
    }
    sort(edge + 1, edge + 1 + m, cmp);
    init(n);
    for (int i = 1; i <= m; i ++)
    {
        int u = edge[i].u, v = edge[i].v;
        u = getf(u);
        v = getf(v);
        if (u != v)
        {
            ans += edge[i].w;
            f[v] = u;
            nedge.push_back(edge[i]);
        }
    }
    for (int i = 0; i < k; i ++)
    {
        cin >> c[i];
        for (int j = 1; j <= n; j ++)
            cin >> a[i][j];
    }
    //cout << ans << endl;
    for (int s = 1; s < (1 << k); s++)
    {
        int sum =0;
        for (int p = s; p; p -= p & -p)
        {
            int f = __builtin_ctz(p);
            sum += c[f];
            for (int i = 1; i <= n; i ++)
                nedge.push_back({n + f + 1, i, a[f][i]});
        }
        vector <Edge> edge = nedge;
        sort(edge.begin(), edge.end(), cmp);
        init(n + k + 1);
        for (auto it : edge)
        {
            int u = it.u, v = it.v;
            //cout << u << " " << v << " " << it.w << endl;
            u = getf(u); v = getf(v);
            if (u != v)
            {
                sum += it.w;
                f[u] = v;
            }
        }
        ans = min(ans, sum);
        for (int p = s; p; p -= p & -p)
        {
            for (int i = 1; i <= n; i ++)
                nedge.pop_back();
        }
    }
    cout << ans << endl;
    return 0;
}