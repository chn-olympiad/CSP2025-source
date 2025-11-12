#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int q[1005][1005];
vector<int >g[10005];
bool vis[1005];
int cum,ans;
void dfs(int n,int p)
{
    for(int i=0;i<g[n].size();i++)
    {
        int to=g[n][i];
        if(to!=p)
        {
            if(!vis[to])
            {
                vis[to]=true;
                cum+=q[to][n];
                dfs(to,n);

            }
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
        g[u].push_back(v);
        g[v].push_back(u);
        q[u][v]=w;
        q[v][u]=w;
    }//Ê÷×´dp???
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            vis[j]=false;
        }
        vis[i]=true;
        dfs(i,0);
        ans=max(ans,cum);
    }
    cout<<ans;
    return 0;
}
