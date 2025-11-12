#include<bits/stdc++.h>
using namespace std;
int n,m,k,fa[10100],ans=0,idx=0;
struct edge{
    int s,to,num;
}adj[10100];
int finds(int x){
    if(fa[x]==x)return x;
    return fa[x]=finds(fa[x]);
}
void merges(int x,int y){
    fa[finds(x)]=finds(y);
}
void kruskra(){
    for(int i=1;i<=n-1;++i){
        if(finds(adj[i].s)!=finds(adj[i].to)){
            ans+=adj[i].num;
            merges(adj[i].s,adj[i].to);
        }
    }
}
bool cmp(edge a1,edge a2){
    return a1.num<a2.num;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=n;++i)fa[i]=i;
    for(int i=1;i<=m;++i){
        int u,v,nnum;
        cin>>u>>v>>nnum;
        adj[++idx]={u,v,nnum};
    }
    sort(adj+1,adj+idx+1,cmp);
    kruskra();
    cout<<ans;
    return 0;
}
