#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;
struct DSU
{
    int fa[10020], siz[10020];
    void init(int n) { for (int i = 1; i <= n; i++) fa[i] = i, siz[i] = 1; }
    int find(int x)
    {
        if (fa[x] == x) return x;
        return fa[x] = find(fa[x]);
    }
    bool merge(int x, int y)
    {
        x = find(x), y = find(y);
        if (x == y) return false;
        if (siz[x] < siz[y]) swap(x, y);
        fa[y] = x, siz[x] += siz[y];
        return true;
    }
} dsu;
struct Node
{
    int u, v, w;
    friend bool operator < (Node x, Node y)
    {
        return x.w < y.w;
    }
} a[1000010];
int c[10];
vector<Node> v[10];
vector<vector<Node>> vv;
vector<Node> merge(vector<Node> x, vector<Node> y)
{
    vector<Node> z;
    int l = 0, r = 0;
    while (l < x.size() && r < y.size())
    {
        if (x[l] < y[r]) z.pb(x[l++]);
        else z.pb(y[r++]);
    }
    while (l < x.size()) z.pb(x[l++]);
    while (r < y.size()) z.pb(y[r++]);
    return z;
}
vector<Node> solve(int l, int r)
{
    if (l == r) return vv[l];
    int mid = l + r >> 1;
    return merge(solve(l, mid), solve(mid + 1, r));
}
signed main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) cin >> a[i].u >> a[i].v >> a[i].w;
    sort(a + 1, a + m + 1);
    dsu.init(n);
    int ans = 0;
    vector<Node> V;
    for (int i = 1; i <= m; i++) if (dsu.merge(a[i].u, a[i].v))
    {
        ans += a[i].w;
        V.pb(a[i]);
    }
    for (int i = 0; i < k; i++)
    {
        cin >> c[i];
        for (int j = 1; j <= n; j++)
        {
            int w;
            cin >> w;
            v[i].pb({n + i + 1, j, w});
        }
        sort(v[i].begin(), v[i].end());
    }
    for (int o = 1; o < (1 << k); o++)
    {
        dsu.init(n + k);
        int sum = 0;
        vv.clear();
        vv.pb(V);
        for (int i = 0; i < k; i++)
        {
            if (!((o >> i) & 1)) continue;
            sum += c[i];
            if (sum >= ans) break;
            vv.pb(v[i]);
        }
        if (sum >= ans) continue;
        vector<Node> vec = solve(0, vv.size() - 1);
        for (auto [u, v, w] : vec) if (dsu.merge(u, v))
        {
            sum += w;
            if (sum >= ans) break;
        }
        ans = min(ans, sum);
    }
    cout << ans << endl;
    return 0;
}