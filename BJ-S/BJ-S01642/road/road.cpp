#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
const int N=1e4+50,M=1e6+1e5+10;

int n,m,k,c[20],tot,co[15][N];
struct Edge {int u,v,w;} e[M],E[M];
LL Ans=1e18;
int f[N];

bool cmp(Edge a,Edge b) {return a.w<b.w;}

int Find(int x){
    if(x==f[x]) return x;
    return f[x]=Find(f[x]);
}

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;++i)
        scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
    for(int i=1;i<=k;++i){
        scanf("%d",&c[i]);
        for(int j=1;j<=n;++j) scanf("%d",&co[i][j]);
    }
    for(int state=0;state<(1<<k);++state){
        if((double)clock()/CLOCKS_PER_SEC>0.95) break;
        memcpy(E,e,sizeof(e)); tot=m; LL res=0;
        int cnt=0,siz=n;
        for(int i=1;i<=k;++i) if((state>>(i-1))&1){
            res+=c[i]; siz++;
            for(int j=1;j<=n;++j) E[++tot]={n+i,j,co[i][j]};
        }
        if(res>=Ans) continue;
        sort(E+1,E+1+tot,cmp);
        for(int i=1;i<=n+k;++i) f[i]=i;
        for(int i=1;i<=tot;++i){
            int u=Find(E[i].u),v=Find(E[i].v);
            if(u==v) continue;
            res+=E[i].w; f[u]=v; cnt++;
            if(cnt==siz-1 || res>=Ans) break;
        }
        Ans=min(Ans,res);
    }
    printf("%lld\n",Ans);
    return 0;
}