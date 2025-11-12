#include<bits/stdc++.h>
#define M 1500000
#define N 20001
using namespace std;
int n,m,k,edgecnt;
int fa[N];
int vill[15][N];
struct Edge{
    int u,v,w;
}edge[M<<1];
void init(){
    for(int i=1;i<=n+k;i++) fa[i]=i;
}
void addedge(int u,int v,int w){
    edge[++edgecnt].v=v;
    edge[edgecnt].u=u;
    edge[edgecnt].w=w;
}
bool cmp(Edge x,Edge y){
    return x.w<y.w;
}
int findfa(int x){
    return fa[x]==x?x:fa[x]=findfa(fa[x]);
}
void solve1(){
    sort(edge+1,edge+1+edgecnt,cmp);
    int ans=0,cnt=0;
    for(int i=1;i<=edgecnt;i++){
        int u=edge[i].u,v=edge[i].v,w=edge[i].w;
        u=findfa(u);
        v=findfa(v);
        if(u==v) continue;
        ans+=w;
        fa[v]=u;
        cnt++;
        if(cnt==n-1) break;
    }
    cout<<ans;
    return;
}
void solve2(){
    for(int i=1;i<=k;i++){
        cin>>vill[i][0];
        for(int j=1;j<=n;j++){
            cin>>vill[i][j];
            addedge(j,n+i,vill[i][j]);
            addedge(n+i,j,vill[i][j]);
        }
    }
    sort(edge+1,edge+1+edgecnt,cmp);
    int ans=0,cnt=0;
    for(int i=1;i<=edgecnt;i++){
        int u=edge[i].u,v=edge[i].v,w=edge[i].w;
        u=findfa(u);
        v=findfa(v);
        if(u==v) continue;
        ans+=w;
        fa[v]=u;
        cnt++;
        if(cnt==n+k-1) break;
    }
    cout<<ans;
    return;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin>>n>>m>>k;
    init();
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        addedge(u,v,w);
        addedge(v,u,w);
    }
    if(k==0) solve1();
    else solve2();
    return 0;
}
