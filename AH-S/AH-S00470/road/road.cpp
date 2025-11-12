#include<bits/stdc++.h>
using namespace std;
struct edge{
    int u,v,w;
}g[1100005];
int n,m,k,cnt;
long long ans;
int fa[10015];
void init(){
    for(int i=1;i<=n+k;i++){
        fa[i]=i;
    }
}
int find(int u){
    if(fa[u]==u) return u;
    return fa[u]=find(fa[u]);
}
bool same(int u,int v){
    return find(u)==find(v);
}
void unite(int u,int v){
    u=find(u);
    v=find(v);
    if(u==v) return;
    fa[u]=v;
}
bool cmp(edge x,edge y){
    return x.w<y.w;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1,u,v,w;i<=m;i++){
        cin>>g[++cnt].u>>g[cnt].v>>g[cnt].w;
    }
    for(int i=1,c;i<=k;i++){
        cin>>c;
        for(int j=1,w;j<=n;j++){
            g[++cnt].u=i+m;
            g[cnt].v=j;
            cin>>g[cnt].w;
        }
    }
    sort(g+1,g+cnt+1,cmp);
    init();
    for(int i=1;i<=cnt;i++){
        if(!same(g[i].u,g[i].v)){
            ans+=g[i].w;
            unite(g[i].u,g[i].v);
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
