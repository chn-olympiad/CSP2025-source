#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
int a[N][N];
int b[N],zs;
typedef long long ll;
ll mx=INT_MAX;
bool vis[N];
int n,m,k;
void dfs(int zb,ll cnt)
{
   // vis[zb]=1;
    bool fg=0;
    for(int i=1;i<=n;i++)
    {
        if(vis[i]==0)
            fg=1;
    }
    if(!fg)
    {
        mx=min(mx,cnt);
        return ;
    }
   // cout<<cnt<<" "<<zb<<endl;

    for(int i=1;i<=n;i++)
    {
        if(a[zb][i]&&vis[i]!=1)
        {
           vis[i]=1;
            dfs(i,cnt+a[zb][i]);
            vis[i]=0;
        }
    }

 //   return ;

}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);

    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        a[u][v]=w;
        a[v][u]=w;
    }
    for(int i=1;i<=k;i++)
    {
        cin>>zs;
        for(int i=1;i<=n;i++)
        {
            cin>>b[i];
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                if(a[i][j]==0) a[i][j]=b[i]+b[j]+zs;
            }
        }
    }
    vis[1]=1;
    dfs(1,0);
    cout<<mx;
    return 0;
}

