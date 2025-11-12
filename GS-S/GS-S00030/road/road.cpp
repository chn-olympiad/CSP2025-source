#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int fa[10005], c[15], a[15][10005];
bool built[15];
struct edge{
    int u,v,w;
}e[2000005];
bool cmp(edge x,edge y) {
    return x.w<y.w;
}
int getfa(int x) {
    if(x==fa[x]) return fa[x];
    return fa[x]=getfa(fa[x]);
}
void mg(int x,int y) {
    x=getfa(x),y=getfa(y);
    if(x!=y) fa[x]=y;
}
void kruskal() {
    for(int i=1;i<=n;i++) fa[i]=i;
    sort(e+1,e+1+m,cmp);
    int ans = 0;
    for(int i=1;i<=m;i++) {
        if(getfa(e[i].u)!=getfa(e[i].v)) {
            ans+=e[i].w;
            mg(e[i].u,e[i].v);
        }
    }
    cout<<ans;
}
int main() {
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    if(k==0) {
        kruskal();
        return 0;
    }
    for(int i=1;i<=m;i++) cin>>e[i].u>>e[i].v>>e[i].w;
    for(int i=1;i<=k;i++) {
        cin>>c[i];
        for(int j=1;j<=n;j++) cin>>a[i][j];
        for(int j=1;j<=n;j++) {
            if(!a[i][j]) {
                for(int k=1;k<=n;k++) e[++m] = {j,k,a[i][k]};
            }
        }
    }
    kruskal();
    return 0;
}
