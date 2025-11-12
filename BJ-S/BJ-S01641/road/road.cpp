#include<bits/stdc++.h>
using namespace std;
const int N=1e6+15;
int n,m,k;
struct edge{
    int v,w;
};
vector<edge> e[N];
int c[15];
bool vis[N];
int prim(){
    int mst=0;
    vis[1]=1;
    for(int u=1;u<=n;u++){
        if(!vis[u]) continue;
        int mind=0x3f3f3f3f,k=-1;
        for(auto i:e[u]){
            int v=i.v,w=i.w;
            if(vis[v]) continue;
            if(w<mind){
                mind=w;
                k=v;
            }
        }
        mst+=mind;
        vis[k]=true;
    }
    return mst;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d %d %d",&n,&m,&k);
    for(int i=1;i<=m;i++){
        int u,v,w;
        scanf("%d %d %d",&u,&v,&w);
        e[u].push_back({v,w});
        e[v].push_back({u,w});
    }
    for(int i=1;i<=k;i++){
        scanf("%d",&c[i]);
        for(int j=1;j<=n;j++){
            int w;
            scanf("%d",&w);
            e[j].push_back({i+n,w});
            e[i+n].push_back({j,w});
        }
    }
    int ans=prim();
    for(int i=1;i<=k;i++) ans+=c[i];
    printf("%d\n",ans);
    return 0;
}