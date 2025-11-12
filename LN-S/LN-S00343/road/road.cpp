#include <bits/stdc++.h>
using namespace std;
const int N = 2e4+25;
const int M = 1e6+25;
int vis[N],p[N];
int fa[N],head[N];int fat[N],d[N];
int a[17][N];
int tmp[17];
int tot,n,m,k,ans;
struct node{
    int u,v,w,Nxt,vis;
}ed[M],e[N];
int b[N],mn[N];
vector<int>stk[17];
void add(int u,int v,int w){
    tot++;ed[tot].u = u;ed[tot].v = v;ed[tot].w = w;
}
void ad(int u,int v,int w){
    tot++;e[tot].u = u;e[tot].v = v;e[tot].w = w;e[tot].Nxt = head[u];head[u] = tot;
}
bool cmp(node A,node B){return A.v < B.v;}
int getfa(int v){
    if(v == fa[v])return v;
    return fa[v] = getfa(fa[v]);
}
void kruskal(){
    sort(ed+1,ed+1+m,cmp);
    for(int i = 1;i<=m;i++){
        int u = ed[tot].u,v = ed[tot].v;
        int fu = getfa(u),fv = getfa(v);
        if(fu != fv){
            ed[tot].vis = 1;
            fa[fu] = fv;
            ans += ed[tot].w;
        }
    }
    tot = 0;
    for(int i = 1;i<=m;i++){
        if(ed[i].vis){
            ad(ed[i].v,ed[i].u,ed[i].w);
            ad(ed[i].u,ed[i].v,ed[i].w);
        }
    }
}
void dfs(int u){
    for(int i = head[u];i;i = e[i].Nxt){
        int v = e[i].v;
        if(v == fat[u])continue;
        fat[v] = u;
        d[v] = e[i].w;
        dfs(v);
    }
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n >> m >> k;
    for(int i =1,u,v,w;i<=m;i++){
        cin >> u >> v >> w;add(u,v,w);
    }
    kruskal();dfs(1);
    cout << ans << endl;

    return 0;
}