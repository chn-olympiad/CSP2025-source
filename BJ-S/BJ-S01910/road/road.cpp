#include <bits/stdc++.h>
using namespace std;

const int NR = 1e4 + 10;
int n, m, k;
struct Edge{
    int to, w;
};
struct Node{
    int x, dis;
};
vector<Edge> g[NR + 15];
int fa[NR + 15];
int dis[NR + 15];
int edge[NR + 15];
int rebuild[NR + 15];
bool vis[NR + 15];
int dfn[NR + 15];
bool need[NR + 15];
int G[NR + 2][NR+ 2];
int tot = 0;
bool Vis[NR +2][NR + 2];
void dfs(int x)
{
    vis[x] = true;
    tot++;
    dfn[x] = tot;
    //cout << x << "\n";
    for(auto y: g[x])
    {
        if(edge[y.to] < y.w + rebuild[y.to] + rebuild[x]) continue;
        if(dfn[y.to] < dfn[x]) continue;
        fa[y.to] = x;
        edge[y.to] = y.w + rebuild[y.to] + rebuild[x];
        if(!vis[y.to])dfs(y.to);
    }
}
int main()
{
    freopen("road.in","r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0);
    cin >>n >>m >>k;
    for(int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >>v >>w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
        G[u][v] = w;
        G[v][u] = w;
    }
    for(int i = 1; i <= k; i++)
    {
        cin >> rebuild[i + n];
        for(int j = 1; j <= n; j++)
        {
            int w;
            cin >> w;
            g[i + n].push_back({j, w});
            g[j].push_back({i + n, w});
            G[i + n][j] = G[j][i + n] = w;
        }
    }
    memset(edge, 0x3f, sizeof(edge));
    vis[1] = true;
    memset(dfn,0x3f,sizeof(dfn));
    edge[1] = 0;
    dfs(1);
    //cout << "\n";
    for(int i = 1; i <= n; i++)
    {
        need[i] = true;
        need[fa[i]] = true;
    }
    long long ans = 0;

    for(int i = 1; i <= n + k; i++)
    {
        if(!need[i]) continue;
        if(Vis[i][fa[i]]) continue;
        ans += G[i][fa[i]];
        ans += rebuild[i];
        ans += rebuild[fa[i]];
    }
    cout << ans << "\n";
    return 0;
}
