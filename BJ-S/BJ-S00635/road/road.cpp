#include <bits/stdc++.h>
using namespace std;

struct edge
{
    int v, c;
};

    int n, m, k;

vector<edge> e[100005];
int vis[100005];
int dis[100005];

void dij(int s)
{
    memset(dis, 0x3f3f3f3f, sizeof(dis));
    dis[s] = 0;
    for (int i = 1; i <= n; i++)
    {
        int u = 0, mind = 0x3f3f3f3f;
        for (int j = 1; j <= n; j++)
        {
            if (!vis[j] && dis[j] < mind)
            {
                dis[j] = mind;
                u = j;
            }
            vis[u] = true;
            for (int j = 0; j < e[u].size(); j++)
            {
                int v = e[u][j].v;
                int c = e[u][j].c;
                if (dis[u] + c < dis[v])
                {
                    dis[v] = dis[u]+c;
                }
            }
        }
    }
}

int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> m >> k;

    for (int i = 1; i <= m; i++)
    {
        int u, v, c;
        cin >> u >> v >> c;
        e[u].push_back(edge{v, c});
        e[v].push_back(edge{u, c});
    }
    for (int i = 1; i <= n+1; i++)
    {
        int sss;
        cin >> sss;
    }
    dij(1);
    cout << dis[n];

}
