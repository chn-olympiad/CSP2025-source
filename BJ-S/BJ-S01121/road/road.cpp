#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k;
struct edge{
    int to,nxt,w;
}e[3000010];
int head[10100],ad=0;
void add(int u,int v,int w)
{
    e[++ad].to=v;
    e[ad].w=w;
    e[ad].nxt=head[u];
    head[u]=ad;
}
int c[20];
int a[20][10100];
bool vis2[20][10100];
bool vis[10100];
int dfs(int u,int dep)
{
    if(dep==n) return 0;
    vis[u]=1;
    int cost=0;
    for(int i=head[u];i;i=e[i].nxt)
    {
        int v=e[i].to;
        int w=e[i].w;
        if(vis[v]) continue;
        cost=min(cost,e[i].w+dfs(v,dep+1));
    }
    for(int i=1;i<=k;i++)
    {
        for(int v=1;v<=n;v++)
        {
            if(vis[v]) continue;
            int cc=1e18;
            if(vis[n+k])
            {
                if(vis2[i][u])
                {
                    vis2[i][v]=1;
                    cost=min(cost,a[i][v]+dfs(v,dep+1));
                    vis2[i][v]=0;
                }
                else
                {
                    vis2[i][u]=vis2[i][v]=1;
                    cost=min(cost,a[i][u]+a[i][v]+dfs(v,dep+1));
                    vis2[i][u]=vis2[i][v]=0;
                }

            }
            else
            {
                vis[n+k]=vis2[i][u]=vis2[i][v]=1;
                cost=min(cost,c[i]+a[i][u]+a[i][v]+dfs(v,dep+1));
                vis[n+k]=vis2[i][u]=vis2[i][v]=0;
            }
        }
    }
    return cost;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        add(u,v,w);
        add(v,u,w);
    }
    for(int i=1;i<=k;i++)
    {
        cin>>c[i];
        for(int j=1;j<=n;j++)
        {
            cin>>a[i][j];
        }
    }
    int ans=1e18;
    for(int i=1;i<=n;i++)
    {
        ans=min(ans,dfs(i,1));
    }
    cout<<ans;
    return 0;
}
