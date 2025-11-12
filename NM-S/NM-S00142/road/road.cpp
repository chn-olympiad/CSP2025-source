#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct Edge{
    ll u,v,w;
};
Edge edge[10000005];
ll fa[10000005];
bool cmp(Edge x,Edge y){
    return x.w<y.w;
}
ll ffind(ll a){
    if(fa[a]==a){
        return a;
    }
    return fa[a]=ffind(fa[a]);
}
int main(){
    for(int i=1;i<=10000000;i++){
        fa[i]=i;
    }
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ll n,m,k;
    scanf("%lld%lld%lld",&n,&m,&k);
    for(int i=1;i<=m;i++){
        scanf("%lld%lld%lld",&edge[i].u,&edge[i].v,&edge[i].w);
    }
    for(int i=1;i<=k;i++){
        int x;scanf("%lld",&x);
        for(int j=1;j<=n;j++){
            edge[m+(i-1)*n+j].u=m+i,edge[m+(i-1)*n+j].v=j;
            scanf("%lld",&edge[m+(i-1)*n+j].w);
        }
    }
    sort(edge+1,edge+k*n+m+1,cmp);
    ll sum=0,ans=0;
    for(int i=1;i<=k*n+m;i++){
        if(ffind(edge[i].u)==ffind(edge[i].v))continue;
        fa[ffind(edge[i].u)]=ffind(edge[i].v);
        sum++;
        ans+=edge[i].w;
        if(sum==n+k-1)break;
    }
    printf("%lld",ans);
    return 0;
}
