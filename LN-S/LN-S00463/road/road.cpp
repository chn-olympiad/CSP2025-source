#include<bits/stdc++.h>
using namespace std;
int n,m,k,ans;
int f[10005],siz[10005];
struct edge{
    int u,v,w;
}g[1000005];
bool cmp(edge A,edge B){
    return A.w<B.w;
}
int fnd(int x){
    if(x==f[x]) return f[x];
    return f[x]=fnd(f[x]);
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>g[i].u>>g[i].v>>g[i].w;
    }
    sort(g+1,g+1+m,cmp);
    for(int i=1;i<=n;i++) f[i]=i,siz[i]=1;
    for(int i=1;i<=m;i++){
        int x=g[i].u;
        int y=g[i].v;
        int z=g[i].w;
        x=fnd(x);
        y=fnd(y);
        if(x==y) continue;
        ans+=z;
        if(siz[x]<siz[y]) swap(x,y);
        siz[x]+=siz[y];
        f[y]=x;
    }
    cout<<ans;
    return 0;
}
