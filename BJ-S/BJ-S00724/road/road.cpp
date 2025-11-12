#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e4 + 10;
const int SIZE = 15;
int n, m, k;
int fa[MAXN], sz[MAXN];
int cnt[SIZE];
long long val[SIZE];
long long c[SIZE], a[MAXN][SIZE];
struct edge
{
    int u;
    int v;
    long long w;
};
vector<edge> e;
int find(int x)
{
    if (x == fa[x])
        return x;
    return fa[x] = find(fa[x]);
}
void merge(int x, int y)
{
    int u = find(x);
    int v = find(y);
    if (u == v)
        return;
    if (sz[u] > sz[v])
    {
        sz[u] += sz[v];
        fa[v] = u;
    }
    else
    {
        sz[v] += sz[u];
        fa[u] = v;
    }
}
bool cmp(const edge &e1, const edge &e2)
{
    return e1.w < e2.w;
}
int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> k;
    for (int i = 1; i <= n + k * 2; i++)
    {
        fa[i] = i;
        sz[i] = 1;
    }
    while (m--)
    {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        e.push_back({u, v, w});
    }
    for (int i = 1; i <= k; i++)
    {
        cin >> c[i];
        for (int j = 1; j <= n; j++)
            cin >> a[j][i];
    }
    for (int i = 1; i <= k; i++)
    {
        for (int j = 1; j <= n; j++)
            e.push_back({n + i, j, a[j][i]});
        e.push_back({n + i, n + k + i, c[i]});
    }
    sort(e.begin(), e.end(), cmp);
    long long ans = 0;
    for (auto i : e)
        if (find(i.u) != find(i.v))
        {
            merge(i.u, i.v);
            ans += i.w;
            if (i.u > n && i.u <= n + k)
            {
                cnt[i.u - n]++;
                val[i.u - n] += i.w;
            }
            if (i.v > n && i.v <= n + k)
            {
                cnt[i.v - n]++;
                val[i.v - n] += i.w;
            }
        }
    for (int i = 1; i <= k; i++)
        if (cnt[i] <= 2)
            ans -= val[i];
    cout << ans << '\n';
    return 0;
}
