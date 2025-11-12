#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
template<typename T>
inline void in (T &x) {
    char c; int f=1;
    do {c=getchar(); (c=='-')&&(f=-1);} while(c>'9'||c<'0');
    for (x=0;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
    x*=f;
}

const int N=1e4+20,M=1e6+5;

int ff[N];
inline int find(int k) {return ff[k]==k?k:ff[k]=find(ff[k]);}
inline bool merge (int u,int v) {
    u=find(u),v=find(v);
    if (u==v) return 0;
    ff[u]=v;
    return 1;
}

struct edge {
    int u,v,w;
    inline bool operator < (const edge &o) const {return w<o.w;}
} tmp[M],e[M],ee[M];
bool vs[M];

int n,m,K;

int c[15],a[15][N];

int main() {
    freopen ("road.in","r",stdin);
    freopen ("road.out","w",stdout);
    in (n),in (m),in (K);
    for (int i=1;i<=m;++i) in (tmp[i].u),in (tmp[i].v),in (tmp[i].w);
    sort(tmp+1,tmp+m+1);
    for (int i=0;i<K;++i) {
        in (c[i]);
        for (int j=1;j<=n;++j) in (a[i][j]);
    }
    int tot=0; ll ans=0,sum;
    for (int i=1;i<=n;++i) ff[i]=i;
    for (int i=1;i<=m;++i) if (merge(tmp[i].u,tmp[i].v)) ans+=tmp[i].w;

    for (int tes=1;tes--;) {
        for (int i=1;i<=n;++i) ff[i]=i;
        for (int i=1;i<=m;++i) if (!vs[i] && merge(tmp[i].u,tmp[i].v)) vs[i]=1,e[++tot]=tmp[i];
    }
    int TOT=tot;
    for (int S=0;S<(1<<K);++S) {
        tot=TOT; sum=0;
        for (int i=1;i<=tot;++i) ee[i]=e[i];
        for (int i=0;i<K;++i) if ((S>>i)&1) {
            sum+=c[i];
            for (int j=1;j<=n;++j) ee[++tot]={n+1+i,j,a[i][j]};
        }
        sort (ee+1,ee+tot+1);
        for (int i=1;i<=n+K;++i) ff[i]=i;
        for (int i=1;i<=tot;++i) if (merge(ee[i].u,ee[i].v)) sum+=ee[i].w;
        ans=min(ans,sum);
    }
    printf ("%lld\n",ans);
    return 0;
}