#include<bits/stdc++.h>
using namespace std;
int n;int m;int k;
struct node{
int v;
int w;
};
long long h,l;int ans=0;int vis[1000005];
vector<node> e[6000001];
int a[15][1000001];int dis[1000001];int c[11];
int dfs(int u){
    if(ans==n){
       l=max(l,h);
    }
    for(int i=1;i<=e[u].size();i++){
            int op=e[u][i].v;
        if(dis[op]<e[u][i].w+dis[op]){
            dis[op]=e[u][i].w+dis[op];
            if(!vis[e[u][i].v]){
                    ans++;vis[i]=1;
            }
            for(int i=1;i<=k;i++){
            if(dis[op]<a[i][op]+c[i]+a[i][e[u][i].v]+a[i][u]){
             h-=dis[op];
             dis[op]=a[i][op]+c[i];
             h+=dis[op];
                e[u].push_back({m+i,a[i][u]});
                e[op].push_back({m+i,a[i][e[u][i].v]});
                e[a[i][u]].push_back({u,a[i][u]});
                e[a[i][e[u][i].v]].push_back({e[u][i].v,a[i][e[u][i].v]});
               }
            }
        }
        dfs(e[u][i].v);
    }
}
int main(){
freopen("road.in","r",stdin);
freopen("road.out","w",stdout);
cin>>n>>m>>k;
for(int i=1;i<=m;i++){
    int u,v,w;
    cin>>u>>v>>w;
    e[u].push_back({v,w});
    e[v].push_back({u,w});
}
for(int i=1;i<=k;i++){
    cin>>c[i];
    for(int j=1;j<=n;j++){
        cin>>a[i][j];
    }
}
memset(dis,1e9,sizeof(dis));
vis[1]=1;
dfs(1);
cout<<l;
return 0;
}
