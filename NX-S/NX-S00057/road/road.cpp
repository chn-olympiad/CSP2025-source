#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAX = 1e5+5;
struct Edge {
    int v, w;
    bool operator> (const Edge &a) const {return w < a.w;};
};
vector<Edge> G[MAX];
priority_queue<Edge, vector<Edge>, greater<Edge>> q;
int n, m, k, s=1;
int vis[MAX], dis[MAX];

void dijkstra()
{
    memset(dis, 0x3f, sizeof(dis));
    dis[s] = 0; q.push({s, 0});
    while(!q.empty())
    {
        int u = q.top().v;
        q.pop();

        if(vis[u]) continue;
        vis[u] = 1;
        for(auto t : G[u])
            if(dis[t.v] > dis[u] + t.w)
                dis[t.v] = dis[u] + t.w,
                q.push({t.v, dis[t.v]});
    }
}

signed main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    
    cin >> n >> m >> k; int dmax=0;
    for(int i=1; i<=m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        G[u].push_back({v, w});
        G[v].push_back({u, w});
        dmax = max({dmax, u, v});
    }
    // cout << dmax << endl;
    for(int i=1; i<=k; i++)
    {
        int c; cin >> c;
        if(c == 0)
        {
            ++dmax;
            for(int j=1; j<=n; j++)
            {
                int w; cin >> w;
                G[dmax].push_back({i, w});
                G[i].push_back({dmax, w});
            }
        }
    }

    // for(int i=1; i<=dmax; i++)
    // {
    //     G[0].push_back({i, 0});
    // }

    dijkstra();
    int ans = 0;
    for(int i=1; i<=dmax; i++) ans = max(ans, dis[i]); // cout << dis[i] << endl, 
    // for(int i=1; i<=dmax; i++) cout << vis[i] << ' ';
    cout << ans << endl;

    return 0;
}