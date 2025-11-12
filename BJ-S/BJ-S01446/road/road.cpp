#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e4+5;
ll n,m,k,c;
ll a[N];
ll b[N];
map<pair<ll,ll>,ll> dis;
bool vis[N];
set<ll> g[N];
ll ans = 0;
//cnt, the current cost.
void dfs(ll cur,ll cnt)//cur, the amount of cities visited
{
    vis[cur] = 1;
    if(cur==n)
    {
        ans = max(ans,cnt);
    }
    for(auto i : g[cur])
    {
        ll u = cur, v = i;
        if(vis[cur+1] == 0)
        {
            vis[cur+1] = 1;
            dfs(cur+1,cnt+dis[{u,v}]);
            vis[cur+1] = 0;
        }
    }
    vis[cur] = 0;
    return;
}

int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i = 1;i<=m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        g[u].insert(v);
        g[v].insert(u);
        dis[{u,v}] = w;
        dis[{v,u}] = w;


    }
    cin>>c;
    for(int i = 1;i<=n;i++)
    {
        cin>>a[i];
    }
    dfs(1,0);
    cout<<ans<<endl;


    return 0;
}
