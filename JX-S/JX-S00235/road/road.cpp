#include <bits/stdc++.h>
using namespace std;
bool f[10037];
int n,m,k,ans=1e9;
struct edge
{
    int to;
    int w;
};
vector<edge>G[10037];
void dfs(int u,int num,int cost)
{
    if(num==n)
    {
        ans=min(ans,cost);
        return;
    }
    for(int i=0;i<G[u].size();i++)
    {
        if(!f[G[u][i].to])
        {
            f[G[u][i].to]=true;
            dfs(G[u][i].to,num+1,cost+G[u][i].w);
            f[G[u][i].to]=false;
        }
    }
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        G[u].push_back((edge){v,w});
        G[v].push_back((edge){u,w});
    }
    for(int i=1;i<=k;i++)
    {
        int x;
        cin>>x;
        for(int i=1;i<=n;i++)
        {
            cin>>x;
        }
    }
    f[1]=true;
    dfs(1,1,0);
    cout<<ans;
    return 0;
}
