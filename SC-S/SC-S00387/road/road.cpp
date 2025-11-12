#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5,M=2e6+5,inf=1e16,K=15;
int n,m,k,tot;
int c[K],a[K][N];
int f[N],siz[N],cnt[N];
struct Edge{
    int u,v,w,tp;
}e[M];
bool cmp(Edge x,Edge y){
    return x.w<y.w;
}
int find(int x){
    return f[x]==x?x:f[x]=find(f[x]);
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%lld%lld%lld",&n,&m,&k);
    for(int i=1,u,v,w;i<=m;i++){
        scanf("%lld%lld%lld",&u,&v,&w);
        e[i]={u,v,w,0};
    }
    tot=m;
    for(int i=1;i<=k;i++){
        scanf("%lld",&c[i]);
        for(int j=1;j<=n;j++){
            scanf("%lld",&a[i][j]);
            e[++tot]={n+i,j,a[i][j],0};
        }
    }
    sort(e+1,e+tot+1,cmp);
    for(int i=0;i<=n+k;i++){
        f[i]=i,siz[i]=1;
    }
    int mst=0;
    for(int i=1;i<=tot;i++){
        int u=e[i].u,v=e[i].v;
        int fu=find(u),fv=find(v);
        if(fu==fv)continue;
        if(siz[fu]<siz[fv])swap(fu,fv);
        // printf("%lld %lld %lld\n",u,v,e[i].w);
        f[fv]=fu,siz[fu]+=siz[fv];
        mst+=e[i].w;
    }
    printf("%lld\n",mst);

    return 0;
}