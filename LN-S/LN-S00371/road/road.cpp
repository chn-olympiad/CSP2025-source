#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,k,f[1100005];
struct Edge{
    ll u,v,w;
}edge[1100005];
int fath(int u){return (f[u]==u)?u:f[u]=fath(f[u]);}
bool cmp(Edge a,Edge b){
    return a.w<b.w;
}
ll ans=0;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++) f[i]=i;
    for(int i=1;i<=m;i++){
        ll u,v,w;
        scanf("%lld%lld%lld",&u,&v,&w);
        edge[i]={u,v,w};
    }
    sort(edge+1,edge+m+1,cmp);
    for(int i=1;i<=m;i++){
        int u=edge[i].u,v=edge[i].v,w=edge[i].w;
        if(fath(u)==fath(v)) continue;
        f[fath(u)]=fath(v);
        ans+=w;
    }
    printf("%lld",ans);
    return 0;
}
//I Love CCF.
