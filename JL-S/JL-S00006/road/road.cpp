#include<bits/stdc++.h>
using namespace std;
struct node
{
    int u,p;
};
vector<node>vec[10005];
int n,m,k,c[15][10005],ans=2e9;
bool vis[10005];
void dfs(int step,int u,int sum)
{
    if(step==n)
    {
        ans=min(ans,sum);
        return;
    }
    for(node x:vec[u])
    {
        if(vis[x.u])continue;
        vis[x.u]=true;
        dfs(step+1,x.u,sum+x.p);
        vis[x.u]=false;
    }
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        int u,v,p;
        cin>>u>>v>>p;
        vec[u].push_back(node{v,p});
        vec[v].push_back(node{u,p});
    }
    for(int i=1;i<=k;i++)
    {
        int w;
        cin>>w;
        c[i][0]=w;
        for(int j=1;j<=n;j++)
        {
            int p;
            cin>>p;
            c[i][j]=p;
        }
    }
    dfs(1,1,0);
    cout<<ans<<endl;
    return 0;
}
