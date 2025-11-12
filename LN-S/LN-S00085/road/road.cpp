#include<bits/stdc++.h>
using namespace std;
struct node{
    long long u,v,w;
};
struct edge{
    long long u,w;
    bool operator<(const edge & b) const{
        return w<b.w;
    }
};
vector<node> adj[10010];
vector<node> adj2[10010];
int n,m,k;
int vis[100010];
int viss[100010];
long long h[10][10010];
long long xc[10010];
long long ans0;
long long  f(int x){
    priority_queue<edge> q;
    for(int i = 1;i<=n;i++) vis[i] = 0;
    long long ans = 0;
    q.push({x,0});
    while(!q.empty()){
        edge u = q.top();
        vis[u.u] = 1;
        ans = u.w;
        for(auto v:adj[u.u]){
            if(!vis[v.v]){
                q.push({v.v,u.w+v.w});
            }
        }
    }
    return ans;
}
long long f2(int x){
    priority_queue<edge> q;
    for(int i = 1;i<=n;i++) vis[i] = 0;
    long long ans = 0;
    q.push({x,0});
    while(!q.empty()){
        edge u = q.top();
        vis[u.u] = 1;
        ans = u.w;
        for(auto v:adj[u.u]){
            if(!vis[v.v]){
                q.push({v.v,u.w+v.w});
            }
        }
        for(int i = 1;i<=k;i++){
            if(viss[i]){
                for(int j = 1;j<=n;j++){
                    if(j == u.u) continue;
                    if(!vis[j]){
                        q.push({j,h[i][j]+h[i][u.u]});
                    }
                }
            }
        }
    }
    return ans;
}
void dfs(int l,int nl,int start){
    if(l == nl){
        long long ans1 = f(1);
        long long ans2 = f(2);
        for(int i = 1;i<=n;i++){
            if(viss[i]) ans2+=xc[i];
        }
        if(ans1>ans2) ans1 = ans2;
        if(ans0>ans1) ans0 = ans1;
    }
    for(int i = start;i<=k;i++){
        viss[i] = 1;
        dfs(l,nl+1,i);
        viss[i] = 0;
    }
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d %d %d",&n,&m,&k);
    long long a,b,c;
    for(int i = 1;i<=m;i++){
        scanf("%lld %lld %lld",&a,&b,&c);;
        adj[a].push_back({a,b,c});
    }
    long long o;
    for(int i = 1;i<=k;i++){
        scanf("%lld",&xc[i]);
        for(int j = 1;j<=n;j++){
            scanf("%lld",&h[i][j]);
        }
    }
    for(int i = 1;i<=n;i++){
        dfs(i,0,1);
    }
    printf("%lld",ans0);
    return 0;
}
