#include<bits/stdc++.h>
using namespace std;
long long n,m,k,a[10005],dis[10005];
struct node{
    long long v,w;
};
long long g[2005][2005];
bool vis[10005];
void prim(){
    memset(vis,0,sizeof(vis));
    memset(dis,0x3f,sizeof(dis));
    long long res=0;
    dis[1]=0;
    while(true){
        int u=-1;
        for( int i=1;i<=n;i++ ){
            if(!vis[i]&&(u==-1||dis[u]>dis[i])){
                u=i;
            }
        }
        if(u==-1) break;
        res+=dis[u],vis[u]=1;
        for(int v=1;v<=n;v++ ){
            if(!vis[v]){
                dis[v]=min(dis[v],g[u][v]);
            }
        }
    }
    cout<<res;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%lld%lld%lld",&n,&m,&k);
    memset(g,0x3f,sizeof(g));
    for( int i=1;i<=m;i++ ){
        long long u,v,w;
        scanf("%lld%lld%lld",&u,&v,&w);
        g[u][v]=g[v][u]=min(g[u][v],w);
    }
    for( int i=1;i<=k;i++ ){
        long long c;
         scanf("%lld",&c);
        for( int j=1;j<=n;j++ ){
            scanf("%lld",&a[j]);
        }
        for( int j=1;j<=n;j++ ){
            for( int k=1;k<j;k++ ){
                g[j][k]=g[k][j]=min(g[j][k],a[j]+a[k]+c);
            }
        }
    }
    prim();
    return 0;
}
