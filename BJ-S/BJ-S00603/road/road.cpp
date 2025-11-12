#include <bits/stdc++.h>
using namespace std;
#define int long long
struct edge
{
    int id, val;
};
struct pedge
{
    int u, v, w;
};
bool cmp(pedge X, pedge Y)
{
    return X.w < Y.w;
}
int n, m, k, ans;
vector<pedge> edges;
vector<edge> g[10005];
bool dfs_find(int now, int t, int pre)
{
    if (now == t) return 1;
    int ans = 0;
    for (edge i : g[now])
    {
        if (i.id != pre) ans = ans || dfs_find(i.id, t, now);
    }
    return ans;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }
    sort(edges.begin(), edges.end(), cmp);
    for (pedge i : edges)
    {
        if (!dfs_find(i.u, i.v, 0))
        {
            ans += i.w;
            g[i.u].push_back({i.v, i.w});
            g[i.v].push_back({i.u, i.w});
        }
    }
    cout << ans;
    return 0;
}
// 西西佛神机保佑我16pts!!!

// 完了完了还有25min要被西西佛肘击了
// freopen("road.in", "r", stdin);
// freopen("road1.out", "w", stdout);
// 我要上洛谷迷惑行为大赏！！！
// 西西佛神机助我一分不挂
// 西西佛神机助我100 + 16 + 0 + 0 = 116
// You have no egg!!!