#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=2e4+5,M=2e6+5;
int n,m,k,ans,fa[N],a[15][N];
struct Edge{
    int x,y,z;
}e[M];

int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}

void MST(){
    sort(e+1,e+m+1,[&](Edge x,Edge y){return x.z<y.z;});
    for(int i=1;i<=m;i++){
        int u=e[i].x,v=e[i].y,w=e[i].z;
        u=find(u),v=find(v);
        if(u!=v)ans+=w,fa[v]=u;
    }
    printf("%lld\n",ans);
}

signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%lld%lld%lld",&n,&m,&k);
    iota(fa+1,fa+n+1,1);
    for(int i=1;i<=m;i++){
        int u,v,w;
        scanf("%lld%lld%lld",&u,&v,&w);
        e[i]={u,v,w};
    }
    if(n>1000)MST();
    else{
        for(int j=1;j<=k;j++){
            int c,pos;
            scanf("%lld",&c);
            for(int i=1;i<=n;i++){
                scanf("%lld",&a[j][i]);
                if(a[j][i]==0)pos=i;
            }
            for(int i=1;i<=n;i++)if(i!=pos)e[++m]={pos,i,a[j][i]};
        }
        MST();
    }
    return 0;
}