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

inline int fpow(int x,int y){
    int r=1;
    for(;y;x=x*x%mod,y>>=1) if(y&1) (r*=x)%=mod;
    return r;
}inline int inv(int x){ return fpow(x,mod-2);}
/*
open a ans size 2^k

sort together,and update what should.

kn2^{k-1}+n2^k)alpha(n)
*/

const int maxn=520;
int f[2][maxn][maxn];
int fac[520];
int c[502];char ss[520];

bool Med;
signed main(){ios::sync_with_stdio(0);cin.tie(0);cerr<<"Used:"<<fixed<<setprecision(2)<<(&Mbe-&Med)/1048576.0<<"MiB\n";
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;cin>>n>>m;
    fac[0]=1;
    rep(i,1,n,1)    (fac[i]=fac[i-1]*i)%=mod;
    rep(i,1,n,1)    cin>>ss[i],ss[i]-='0';
    rep(i,1,n,1){
        int x;cin>>x;c[x]++;
    }
    per(i,n,0,1)    c[i]+=c[i+1];
    // sort(c+1,c+1+n);
    rep(j,m,n,1)    f[n+1&1][n+1-j][0]=1;
    per(i,n,1,1){
        memset(f[i&1],0,sizeof(f[i&1]));
        rep(j,0,i+1,1)    rep(k,0,n,1)  if(f[i+1&1][j][k]){
            //qian j ge
            // c_i must >t
            if(ss[i]){
                // if(i!=j)    
                (f[i&1][j][k+1]+=f[i+1&1][j][k]*(c[j]-k))%=mod;
                // c_i must <=t
                if(j){
                    (f[i&1][j-1][k+1]-=f[i+1&1][j][k]*(c[j-1]-k))%=mod;
                    (f[i&1][j-1][k]+=f[i+1&1][j][k])%=mod;
                }
            }else{
                if(j)   (f[i&1][j-1][k]+=f[i+1&1][j][k])%=mod;
            }
        }
    }
    int ans=0;
    rep(k,0,n,1){
        int t=n-k;
        (ans+=f[1][1][k]*fac[t])%=mod;
    }
    // rep(k,m,n,1)    (ans+=f[n&1][(1<<n)-1][k])%=mod;
    ans+=mod;ans%=mod;
    cout<<ans<<'\n';
    return 0;
}