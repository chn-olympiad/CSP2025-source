// Will I win? - 14:42
#include <bits/stdc++.h>
#define int long long
#define rep(i,a,b,c)    for(int i=(a);i<=(b);i+=(c))
#define per(i,a,b,c)    for(int i=(a);i>=(b);i-=(c))
#define pb push_back
#define pii pair<int,int>
#define vint vector<int>

using namespace std;

const int mod=998244353;
bool Mbe;
const int maxn=1.02e4;
const int maxm=1.02e6;

inline int fpow(int x,int y){
    int r=1;
    for(;y;x=x*x%mod,y>>=1) if(y&1) (r*=x)%=mod;
    return r;
}inline int inv(int x){ return fpow(x,mod-2);}

array<int,3> a[maxm],b[maxn],tt[maxn*12];
int fa[maxn];
int get(int u){ return (u==fa[u]?u:fa[u]=get(fa[u]));}
int c[12];

/*
open a ans size 2^k

sort together,and update what should.

kn2^{k-1}+n2^k)alpha(n)
*/


bool Med;
signed main(){ios::sync_with_stdio(0);cin.tie(0);cerr<<"Used:"<<fixed<<setprecision(2)<<(&Mbe-&Med)/1048576.0<<"MiB\n";
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;cin>>n>>m>>k;
    iota(fa+1,fa+1+n,1);
    rep(i,1,m,1)    cin>>a[i][1]>>a[i][2]>>a[i][0];
    sort(a+1,a+1+m);
    int ca=0;
    rep(i,0,k-1,1){
        cin>>c[i];
        rep(j,1,n,1){
            ca++;
            cin>>tt[ca][0],tt[ca][1]=n+i+1,tt[ca][2]=j;
        }
   }
    // int cc=0;
    int ans=0;
    rep(i,1,m,1){
        auto [w,u,v]=a[i];
        if(get(u)!=get(v))      tt[++ca]=a[i],fa[get(u)]=get(v),ans+=w;
    }
    sort(tt+1,tt+1+ca);
    // cerr<<"!!!"<<cc<<endl;
    rep(s,0,(1<<k)-1,1){
        int cur=0;
        rep(i,0,k-1,1)  if(s>>i&1)  cur+=c[i];
        if(cur>=ans)    continue ;
        iota(fa+1,fa+1+n+k,1);
        int tot=n+__builtin_popcount(s)-1;
        rep(i,1,ca,1){
            auto [w,u,v]=tt[i];
            if(u>n && (~s>>(u-n-1)&1))  continue ;
            if(get(u)!=get(v))  fa[get(u)]=get(v),cur+=w,tot--;
            if(cur>ans || !tot) break ;
        }
        ans=min(ans,cur);
    }
    cout<<ans<<'\n';
    return 0;
}