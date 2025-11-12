#include<bits/stdc++.h>
using namespace std;

struct edge
{
    int to;
    int cost;
    edge(int x, int y)
    {
        to = x;
        cost = y;
    }
};

vector<edge> edges[1000005];
queue <int> q;
int dis[10005];
bool vis[10005];
int s;
inline void spfa()
{
    memset(dis, 255, sizeof(dis));
    memset(vis, false, sizeof(vis));
    q.push(s);
    dis[s] = 0;
    vis[s] = 1;
    while(!q.empty())
    {
        int u = q.front();
        for(auto i : edges[u])
        {
            int v = i.to;
            if(dis[v] > dis[u] + i.cost)
            {
                dis[v] = dis[u] + i.cost;
                if(!vis[v])
                {
                    q.push(v);
                    vis[v] = 1;
                }
            }

        }
        vis[u] = 0;
        q.pop();

    }
}
int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges[u].push_back(edge(v, w));
        edges[v].push_back(edge(u, w));
    }

    s = 1;

    spfa();
    long long ans = 0;
    for(int i = 1; i <= n; i++)
    {
        ans += dis[i];
    }
    cout << ans;
}
