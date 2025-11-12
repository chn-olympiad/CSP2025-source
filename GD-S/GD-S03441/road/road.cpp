#include<bits/stdc++.h>
using namespace std;
const int N = 2e6+5,M=1e4+5;
typedef long long ll;
// struct Edge{int to,nxt,val;}e[N<<2];int head[N],Ecnt;
// void add(int u,int v,int w){
//     e[++Ecnt] = {v,head[u],w};
//     head[u] = Ecnt;
// }

struct Path{
    ll from,to,val;
    friend bool operator<(Path a,Path b){
        return a.val<b.val;
    }
}path[N<<2];

int p[M];
int fd(int x){
    return p[x] == x ? x:p[x] = fd(p[x]);
}
int n,m,k;
bool vis[21];
int c[21];
Path pt[21][M];
Path pp[N<<2];
ll kruskal(){
    ll res = 0,Ecnt = 0,tot = n;
    for(int i=1;i<=m;i++) pp[++Ecnt] = path[i];
    for(int i=1;i<=k;i++){
        if(vis[i]==1) {
            res += c[i];
            tot++;
            for(int j=1;j<=n;j++){
                pp[++Ecnt] = pt[i][j];
            }
        }
    }
    for(int i=1;i<=n+k;i++){
        p[i] =i;
    }
    sort(pp+1,pp+1+Ecnt);
    for(int i=1;i<=Ecnt;i++){
        int f = pp[i].from,t=pp[i].to;
        if(fd(f)==fd(t)) continue;
        p[fd(f)] = fd(t);
        tot --;
        res += pp[i].val;
        if(tot==1) return res;
    }
    return 3e18;
}
ll ans = 2e18;
void dfs(int cur){
    if(cur == k){
        vis[cur] = 1;
        ans = min(ans,kruskal());
        vis[cur] = 0;
        ans = min(ans,kruskal());
        return;
    }
    else{
        vis[cur] = 1;
        dfs(cur+ 1);
        vis[cur] = 0;
        dfs(cur+1);
    }
    return;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        path[i] = {u,v,w};
    }
    bool is = 1;
    for(int i=1;i<=k;i++){
        cin>>c[i];
        if(c[i] > 0) is = 0;
        for(int j=1;j<=n;j++){
            int w;cin>>w;
            if(w > 0) is = 0;
            pt[i][j] = {n+i,j,w};
        }
    }
    if(is) cout<<0,exit(0);
    dfs(1);
    cout<<ans;
    return 0;
}