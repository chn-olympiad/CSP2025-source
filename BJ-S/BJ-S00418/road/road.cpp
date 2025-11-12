#include <bits/stdc++.h>
using namespace std;
int e[10005][10005];
int vis[10005],dis[10005];
long long ans;

int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        e[u][v]=w;
        e[v][u]=w;
    }
    vis[1]=1;
    memset(dis,1000000007,sizeof(dis));
    int x=1;
    for(int i=1;i<=n;i++){
        vis[x]=1;
        for(int j=1;j<=n;j++){
            if(e[x][j]!=0){
                dis[j]=min(dis[j],e[x][j]);
            }
        }
        int flag=1;
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                flag=0;
                break;
            }
        }
        if(flag){
            break;
        }
        int minn=0;
        for(int i=1;i<=n;i++){
            if(dis[minn]>dis[i] && !vis[i]){
                minn=i;
            }
        }
        ans+=dis[minn];
        x=minn;
    }
    cout<<ans;
    return 0;
}
