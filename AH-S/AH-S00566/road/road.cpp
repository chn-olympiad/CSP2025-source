#include <bits/stdc++.h>
using namespace std;
#define int long long
const int LEN = 1e4 + 5;
int n, m, k, dis[LEN], vis[LEN], ans = 0;
struct edge
{
    int to, w;
};
struct node
{
    int id, dist;
    bool operator<(const node &x) const
    {
        return dist > x.dist;
    }
};
vector<edge> G[LEN];
priority_queue<node> pq;
void dij(int s)
{
    for (int i = 1; i <= n; i++)
        dis[i] = LONG_LONG_MAX;
    dis[s] = 0;
    pq.push({s, 0});
    while (!pq.empty())
    {
        node u = pq.top();
        pq.pop();
        // cout << "== u:" << u.id << "\n";
        if (vis[u.id] == 1)
            continue;
        vis[u.id] = 1;
        for (edge e : G[u.id])
        {
            // cout << "=== e:" << e.to << "\n";
            if (dis[u.id] + e.w < dis[e.to])
            {
                ans += e.w;
                dis[e.to] = dis[u.id] + e.w;
                // cout << "=== e.to had changed to " << dis[e.to] << "\n";
                pq.push({e.to, dis[e.to]});
            }
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }
    dij(1);
    // int ans = 0;
    // for (int i = 1; i <= n; i++)
    //     cout << dis[i] << " ";
    // for (int i = 1; i <= n; i++)
    //     ans += dis[i];
    cout << ans;
    return 0;
}