#include <bits/stdc++.h>

using namespace std;

#define fileio(x,y) freopen(x,"r",stdin),freopen(y,"w",stdout);
#define tup tuple<int,int,int>
#define fir(x) (get<0>(x))
#define sec(x) (get<1>(x))
#define thr(x) (get<2>(x))
#define pii pair<int,int>
#define bit(x) bitset<x>
#define pb emplace_back
#define i12 __int128_t
#define mt make_tuple
#define ll long long
#define mp make_pair

const int   mod=998244353;

const int   maxk=(1<<10)+10;
const int   maxn=1e4+110;
const int   maxm=1e6+10;

tup             tr[maxk][maxn];
tup             e[maxm];
pii             a[20][maxn];
int             fa[maxn],c[20];
int             n,m,k;

inline char nc() { static char buf[1<<25],*p1=buf,*p2=buf; return (p1==p2&&(p2=p1+fread(buf,1,1<<25,stdin),p1==p2)? EOF:*p1++); }
inline int read() { int x=0,f=1; char c; while(!isdigit(c=nc())) if(c=='-') f=-1; while(isdigit(c)) { x=x*10+c-'0'; c=nc(); } return x*f; }

inline int find(int x) { return (fa[x]==x? x:(fa[x]=find(fa[x]))); }
inline bool merge(int x,int y) { x=find(x),y=find(y); if(x==y) return false; fa[x]=y; return true; }

ll calc(int now,int id,int nxt)
{
    for(int i=1; i<=n+k; i++) fa[i]=i;
    ll res=0; int pos=1,siz=0,lst=n+__builtin_popcount(now)-1;
    // for(auto [val,u,v]:tr[now])
    for(int i=0; i<lst; i++)
    {
        int val=fir(tr[now][i]),u=sec(tr[now][i]),v=thr(tr[now][i]);
        while(pos<=n&&fir(a[id][pos])<=val)
        {
            if(merge(id+n+1,sec(a[id][pos])))
                tr[nxt][siz++]=mt(fir(a[id][pos]),id+n+1,sec(a[id][pos])),res+=fir(a[id][pos]);
            pos++;
        }
        if(merge(u,v)) tr[nxt][siz++]=mt(val,u,v),res+=val;
        if(siz==lst+1) return res;
    }
    return res;
}

void work()
{
    /* Code */
    n=read(),m=read(),k=read(); ll tar=0;
    for(int i=1,x,y,z; i<=m; i++) x=read(),y=read(),z=read(),e[i]=mt(z,x,y);
    for(int i=0; i<k; i++) { c[i]=read(); for(int j=1; j<=n; j++) fir(a[i][j])=read(),sec(a[i][j])=j; }
    for(int i=0; i<k; i++) sort(a[i]+1,a[i]+n+1);
    sort(e+1,e+m+1); for(int i=1; i<=n; i++) fa[i]=i; int siz=0;
    for(int i=1; i<=m; i++) if(merge(sec(e[i]),thr(e[i]))) tar+=fir(e[i]),tr[0][siz++]=(e[i]);
    for(int st=1; st<(1<<k); st++)
    {
        ll ex=0,lst=-1;
        for(int i=k-1; ~i; i--) if((st>>i)&1) { ex+=c[i]; if(!~lst) lst=i; }
        tar=min(tar,calc(st^(1<<lst),lst,st)+ex);
    }
    cout<<tar<<'\n';
    return;
}

signed main()
{
    fileio("road.in","road.out");
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    t=1;
    while(t--) work();
    return 0;
} // Cellinia Texas.
