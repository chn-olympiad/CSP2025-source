#include<bits/stdc++.h>
using namespace std;
#define int long long
int ans=1145141919;
int fa[10019];
int c[19];
int a[19][10019];
struct edge{
int u,v,w;
bool operator<(const edge x)const{
return w<x.w;
}

}e[3000009],nw[3000009];
vector<edge> vec[10019];
int deg[10019];
int n,m,k;
inline int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
int cnt=0;
int tmp=0;
inline void merge(int x,int y,int z){
int fx=find(x),fy=find(y);
if(fx==fy)return;
nw[++cnt]={x,y,z};
vec[x].push_back({y,z});
vec[y].push_back({x,z});
deg[x]++,deg[y]++;
tmp+=z;
fa[fy]=fx;

}
inline int kruskal(){
    sort(e+1,e+1+m);
for(int i=1;i<=m;i++){
int u=e[i].u,v=e[i].v,w=e[i].w;
merge(u,v,w);
if(cnt==n-1){
   return tmp;
}
}

return -1;
}
int stcnt,st[2222];
inline void dfs(int x,int state){
if(x==k){
    st[++stcnt]=state;
    return;
}
dfs(x+1,state);
dfs(x+1,state | (1<<x));
}
int dis[10019];
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);


cin>>n>>m>>k;
bool ok=1;
for(int i=1;i<=n+k;i++)fa[i]=i;
for(int i=1;i<=m;i++)cin>>e[i].u>>e[i].v>>e[i].w;
for(int i=1;i<=k;i++){
    cin>>c[i];
    if(c[i]!=0)ok=0;
    for(int j=1;j<=n;j++)cin>>a[i][j];
}
if(ok){
for(int i=1;i<=k;i++){
    for(int j=1;j<=n;j++){
        if(j==i)continue;
        e[++m]={i+n,j,a[i][j]};
    }
}
n+=k;
}

cout<<kruskal()<<endl;
return 0;
}
