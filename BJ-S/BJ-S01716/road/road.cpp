#include<bits/stdc++.h>
using namespace std;
#define ll long long
constexpr int N=1e4+5,M=1e6+5;
int n,m,k,fa[N+10];
ll ans;
struct edge{
    int u,v,w;
}e[M+10*N];
bool cmp(edge a,edge b){
    return a.w<b.w;
}
int find(int x){
    return x==fa[x]?x:fa[x]=find(fa[x]);
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++) scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
    for(int i=1,tmp;i<=k;i++){
        scanf("%d",&tmp);
        for(int j=1,val;j<=n;j++){
            scanf("%d",&val);
            e[++m]={i+n,j,val};
        }
    }
    sort(e+1,e+m+1,cmp);
    for(int i=1;i<=n+k;i++) fa[i]=i;
    for(int i=1;i<=m;i++){
        int u=e[i].u,v=e[i].v,w=e[i].w;
        int fu=find(u),fv=find(v);
        if(fu!=fv){
            fa[fu]=fv;
            ans+=w;
        }
    }
    printf("%lld\n",ans);
    return 0;
}
