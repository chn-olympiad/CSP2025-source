#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define qwq Ff472130
#define f(i,l,r) for (int i=l;i<=r;i++)
#define F(i,r,l) for (int i=r;i>=l;i--)
const int N=2e6+10;
const ll inf=1e18+7;

inline void read(int &x) {
    x=0;
    char ch=getchar();
    while (ch<48) ch=getchar();
    while (ch>=48) x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
}

int n,m,k;
ll ans=inf;

struct Edge{int u,v,w;}e[N];
inline bool cmp(Edge a,Edge b) {return a.w<b.w;}

int f[N];
inline int find(int x) {
    if (f[x]==x) return x;
    return f[x]=find(f[x]);
}

inline void solve() {
    ll res=0;
    sort(e+1,e+1+m,cmp);
    f(i,1,n) f[i]=i;
    f(i,1,m) {
        int x=e[i].u,y=e[i].v,w=e[i].w;
        if (find(x)==find(y)) continue;
        f[find(x)]=find(y);
        res+=w;
    }
    ans=min(ans,res);
}

int main() {
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    read(n);read(m);read(k);
    f(i,1,m) read(e[i].u),read(e[i].v),read(e[i].w);
    solve();
    f(T,1,k) {
        int val,now=++n;
        read(val);
        f(i,1,n-T) {
            read(val);
            e[++m]={now,i,val};
        }
    }
    solve();
    printf("%lld\n",ans);
    return 0;
}
