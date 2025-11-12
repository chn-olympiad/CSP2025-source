#include <bits/stdc++.h>
using namespace std;
struct edge
{
    int u, v, w;
    bool operator<(const edge &b) const { return w < b.w; }
};
vector<int> fa;
int find(int x)
{
    if (fa[x] == x)
        return x;
    return fa[x] = find(fa[x]);
}
void merge(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x != y)
    {
        fa[x] = y;
    }
}
vector<edge> mp;
int main()
{
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    mp.resize(m + 1);
    int cnt = n;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        mp[i] = {u, v, w};
        mp[i] = {v, u, w};
    }
    for (int i = 1; i <= k; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            mp.push_back({++cnt, j, 0});
            mp.push_back({j, cnt, 0});
        }
    }
    int dist = 0;
    sort(mp.begin() + 1, mp.end());
    for (int i = 1; i <= mp.size() - 1; i++)
    {
        int u = mp[i].u, v = mp[i].v, w = mp[i].w;
        if (find(v) != find(u))
        {
            merge(u, v);
            dist += w;
        }
    }
    cout << dist;
}