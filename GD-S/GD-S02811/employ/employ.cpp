#include <bits/stdc++.h>
using namespace std;
#define fo(i,l,r) for(int i=(l);i<=(r);++i)
#define fd(i,r,l) for(int i=(r);i>=(l);--i)
#define fu(i,l,r) for(int i=(l);i<(r);++i)
#define ll long long
#define ull unsigned long long
#define it128 __int128
#define vi vector<int>
#define pi pair<int,int>
#define fi first
#define se second
#define vp vector<pi>
#define pl pair<ll,ll>
#define eb emplace_back
#define Size(x) ((int)x.size())
const int N=505,mod=998244353;
int mul(const int &x,const int &y) {return (ull)x*y%mod;}
void inc(int &x,int y) {x+=y; if(x>=mod) x-=mod;}
int fac[N],inv[N];
int pow1(int x,int y) {
    int res=1;
    for(;y;y>>=1,x=(ull)x*x%mod) if(y&1) res=(ull)res*x%mod;
    return res;
}
int binom(int x,int y) {
    if(x<y||x<0||y<0) return 0;
    return (ull)fac[x]*inv[y]%mod*inv[x-y]%mod;
}
int n,m,c[N];
char str[N];
int bz[N],p[N],ans=0;
void dfs(int x) {
    if(x>n) {
        int s=0;
        fo(i,1,n) {
            if(str[i]=='0'||c[p[i]]<=s) {
                ++s;
            }
        }
        if(s<=n-m) {
            // cout<<p[1]<<' '<<p[2]<<' '<<p[3]<<' '<<s<<'\n';
            ++ans;
        }
        return;
    }
    fo(i,1,n) if(!bz[i]) p[x]=i,bz[i]=1,dfs(x+1),bz[i]=0;
}
signed main() {
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    fac[0]=1,inv[0]=1;
    fu(i,1,N) fac[i]=mul(fac[i-1],i),inv[i]=pow1(fac[i],mod-2);
    scanf("%d%d",&n,&m);
    scanf("%s",str+1);
    fo(i,1,n) scanf("%d",&c[i]);
    dfs(1);
    cout<<ans<<'\n';
}