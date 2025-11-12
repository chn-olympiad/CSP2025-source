#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e4+10,M=1e6+10,K=20,INF=1e17;
struct NODE{
    ll v;
    ll w;
};
vector< vector<NODE> > g(N+K);
ll c[K],a[K][N],n,m,k,minc=INF;
void addarr(int x,int tot){
    for(int i=1;i<=n;i++){
        g[n+tot].push_back({i,a[x][i]});
        g[i].push_back({x,a[x][i]});
    }
    return;
}
void minusarr(int x,int tot){
    for(int i=1;i<=n;i++){
        g[n+tot].pop_back();
        g[i].pop_back();
    }
    return;
}
void prim(int x,ll extra){
    ll minx=0,dist[N+K];
    bool is[N+K];
    memset(is,0,sizeof(is));
    is[1]=true;
    for(int i=1;i<=x;i++) dist[i]=INF;
    for(auto nd : g[1]){
        dist[nd.v]=nd.w;
    }
    dist[1]=0;
    for(int i=2;i<=x;i++){
        ll mini=INF,u;
        for(int j=1;j<=x;j++){
            if(mini>dist[j]&&is[j]==false) mini=dist[j],u=j;
        }
        minx+=mini;
        is[u]=true;
        for(auto nd : g[u]){
            if(is[nd.v]==false&&dist[nd.v]>nd.w){
                dist[nd.v]=nd.w;
            }
        }
    }
    minc=min(minc,minx+extra);
    return;
}
void dfs(int tot,int last,int extra){
    if(tot==k+1) return;
    for(int i=last+1;i<=k;i++){
        extra+=c[i];
        addarr(i,tot);
        prim(n+tot,extra);
        dfs(tot+1,i,extra);
        minusarr(i,tot);
        extra-=c[i];
    }
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    for(int j=1;j<=k;j++){
        cin>>c[j];
        for(int i=1;i<=n;i++) cin>>a[j][i];
    }
    dfs(1,0,0);
    prim(n,0);
    cout<<minc;
    return 0;
}
//g++ -o test test.cpp -O2 -std=c++14 -static
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
