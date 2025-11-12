#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll N=10005, M=3000005, K=15;
ll n, m, k, c[K], a[K][N], ans=0, fa[N], cnt0=0;
struct Edge{
    ll u, v, w;
    friend bool operator<(Edge a, Edge b){
        return a.w<b.w;
    }
}edge[M];
ll find(ll x){
    if(x==fa[x]) return fa[x];
    return fa[x]=find(fa[x]);
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%lld%lld%lld",&n,&m,&k);
    for(ll i=1;i<=m;i++){
        ll u, v, w;
        scanf("%lld%lld%lld",&u,&v,&w);
        edge[++cnt0]={u,v,w};
    }
    for(ll i=1;i<=k;i++){
        scanf("%lld",&c[i]);
        ll x=0;
        for(ll j=1;j<=n;j++){
            scanf("%lld",&a[i][j]);
            if(a[i][j]==0) x=j;
        }
        for(ll j=1;j<=n;j++) edge[++cnt0]={x,j,a[i][j]};
    }
    sort(edge+1,edge+cnt0+1);
    for(ll i=1;i<=n;i++) fa[i]=i;
    for(ll i=1;i<=cnt0;i++){
        ll u=edge[i].u, v=edge[i].v, w=edge[i].w;
        if(find(u)==find(v)) continue;
        ans+=w, fa[find(u)]=find(v);
    }
    return printf("%lld",ans)&0;
}