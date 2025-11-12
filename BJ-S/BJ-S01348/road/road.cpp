#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=1e4+5;
const int M=1e6+5;

template<typename T>
inline void read(T &x) {
    x=0;char c=getchar();
    for(;!isdigit(c);c=getchar());
    for(;isdigit(c);c=getchar())x=x*10+c-'0';
}

struct EDGE {
    int u,v,w;
    bool operator < (const EDGE &rhs) const {
        return w<rhs.w;
    }
}edge[M],e[M];
int n,m,k,fa[N+10],a[10][N],c[10];
inline int getfa(int x) {
    if(x==fa[x])return fa[x];
    return fa[x]=getfa(fa[x]);
}
LL ans=0;
int main() {
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    read(n),read(m),read(k);
    for(int i=1,u,v,w;i<=m;i++) {
        read(u),read(v),read(w);
        edge[i]={u,v,w};
    }
    sort(edge+1,edge+m+1);
    int cnt=0;
    for(int i=1;i<=n;i++)fa[i]=i;
    for(int i=1;i<=m;i++) {
        int u=getfa(edge[i].u),v=getfa(edge[i].v);
        if(u==v)continue;
        e[++cnt]=edge[i];
        ans+=edge[i].w;
        fa[u]=v;
    }
    bool flg=1;
    for(int i=1;i<=cnt;i++)edge[i]=e[i];
    for(int i=0;i<k;i++) {
        read(c[i]);
        if(c[i]!=0)flg=0;
        for(int j=1;j<=n;j++)
            read(a[i][j]);
    }
    for(int S=0;S<(1<<k);S++) {
        if(flg)S=(1<<k)-1;
        LL res=0;cnt=n-1;
        for(int i=1;i<=cnt;i++)e[i]=edge[i];
        for(int i=0;i<k;i++)if(S>>i&1)res+=c[i];
        if(res>=ans)continue;
        for(int i=0;i<k;i++) if(S>>i&1)
            for(int j=1;j<=n;j++)
                e[++cnt]={n+i+1,j,a[i][j]};
        sort(e+1,e+cnt+1);
        for(int i=1;i<=n+k;i++)fa[i]=i;
        for(int i=1;i<=cnt&&res<ans;i++) {
            int u=getfa(e[i].u),v=getfa(e[i].v);
            if(u==v)continue;
            fa[u]=v;
            res+=e[i].w;
        }
        ans=min(ans,res);
        if(flg)break;
    }
    printf("%lld\n",ans);
    return 0;
}
