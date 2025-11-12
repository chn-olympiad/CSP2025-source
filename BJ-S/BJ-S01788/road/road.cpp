#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define f first
#define se second
#define pb push_back
using namespace std;
int n,m,k,u,v,w,a[20][10010],dis[100010];
bool vis[10010];
vector<pii> e[10010];
priority_queue<pii,vector<pii>,greater<pii> > q;
void dijkstra()
{
    for(int i = 1;i <= n;i++) dis[i] = 2e15;
    dis[1] = 0;
    q.push({0,1});
    while(!q.empty())
    {
        int x = q.top().f,y = q.top().se;
        q.pop();
        if(vis[y]) continue;
        vis[y] = 1;
        for(int i = 0;i < e[y].size();i++) if(dis[e[y][i].f] > x + e[y][i].se)
        {
            dis[e[y][i].f] = x + e[y][i].se;
            if(!vis[e[y][i].f]) q.push({dis[e[y][i].f],e[y][i].f});
        }
    }
}
signed main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n >> m >> k;
    for(int i = 1;i <= m;i++) cin >> u >> v >> w,e[u].pb({v,w}),e[v].pb({u,w});
    dijkstra();
    int ans = 0;
    for(int i = 1;i <= n;i++) ans = max(ans,dis[i]);
    cout << ans << endl;
    return 0;
}
