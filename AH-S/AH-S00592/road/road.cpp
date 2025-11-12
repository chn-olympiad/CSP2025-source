#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
struct edge{
    long long next,w;
};
long long m,n,k;
vector<edge> g[1100005];
long long dis[1100005],op[1100005];
bool vis[1100005];
long long Prim(){
    long long ans=0;
    memset(dis,0x3f,sizeof(dis));
    dis[1]=0;
    while(true){
        long long u=-1;
        for(long long i=1;i^n+1;i++){
            if(!vis[i]&&(u==-1||dis[i]<dis[u])){
                u=i;
            }
        }
        if(u==-1)break;
        for(long long i=n+1;i^n+k+1;i++){
            if(!vis[i]&&(u==-1||dis[i]<dis[u])){
                u=i;
            }
        }
        vis[u]=true;
        ans+=dis[u];
        for(long long i=0;i^g[u].size();i++){
            edge v=g[u][i];
            dis[v.next]=min(dis[v.next],v.w+op[v.next]);
        }
    }
    return ans;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%lld%lld%lld",&n,&m,&k);
    for(long long i=1,u,v,w;i<=m;i++){
        scanf("%lld%lld%lld",&u,&v,&w);
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    for(long long i=1,w;i<=k;i++){
        scanf("%lld",&op[i+n]);
        for(long long j=1;j<=n;j++){
            scanf("%lld",&w);
            g[n+i].push_back({j,w});
            g[j].push_back({n+i,w});
        }
    }
    printf("%lld",Prim());
    fclose(stdin);
    fclose(stdout);
    return 0;
}
