#include<bits/stdc++.h>
using namespace std;
struct edge
{
    int v,w;
};
vector<edge> g[10005];
int dis[10005],vis[10005];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k,ans=0;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        ans+=c;
        g[a].push_back({b,c});
        g[b].push_back({a,c});
    }
    int t;
    for(int i=1;i<=k;i++)
        for(int j=1;j<=n+1;j++)
            cin>>t;
    /*for(int i=2;i<10005;i++)
        dis[i]=1e9;
    dis[1]=0;
    for(int i=1;i<n;i++)
    {
        int u,minl=1e9;
        for(int j=0;j<g[i].size();j++)
            if(dis[j]<minl)
                u=j;
        vis[u]=1;
        for(int v=0;v<g[u].size();v++)
            if(dis[u]+g[u][v].w<dis[v])
                dis[v]=dis[u]+g[u][v].w;
    }
    for(int i=1;i<=n;i++)
        ans=max(ans,dis[i]);*/
    cout<<ans<<endl;
    return 0;
}
