#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<queue>
#include<cstring>
using namespace std;

struct node
{
    int id;
    int v;
};
int n,m,k;
int a[1015][1015],c[15],w[15][1005];
bool vis[1015];
queue<node> q;
long long ans=1e18;

void dfs(int step,int t,long long sum)
{
   if(step>n)
   {
       ans=min(ans,sum);
       return ;
   }
   for(int i=1;i<=n;i++)
   {
       if(vis[i])continue;
       if(a[t][i]==-1)continue;
       vis[i]=true;
       dfs(step+1,i,sum+a[t][i]);
       vis[i]=false;
   }
   if(t>n)return ;
   for(int i=n+1;i<=n+k;i++)
   {
       if(a[t][i]==-1)continue;
       if(!vis[i])
       {
           vis[i]=true;
           dfs(step,i,sum+a[t][i]+c[i-n]);
            vis[i]=false;
       }
       else
       {
           dfs(step,i,sum+a[t][i]);
       }
   }
}

int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=n+k;i++)
    {

        for(int j=1;j<=n+k;j++)
        {

            a[i][j]=-1;
        }
    }
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        a[u][v]=a[v][u]=w;
    }
    for(int i=1;i<=k;i++)
    {
        cin>>c[i];
        for(int j=1;j<=n;j++)
        {
            cin>>w[i][j];
            a[j][n+i]=a[n+i][j]=w[i][j];
        }
    }
    dfs(1,1,0);

    cout<<ans<<endl;

    return 0;
}
