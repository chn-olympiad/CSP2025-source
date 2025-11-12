#include<bits/stdc++.h>
using namespace std;
#define reg register
#define _ 27
#define __ 1000007
#define ___ 0x3f3f3f3f
#define mem(a,x) memset(a,x,sizeof(a))
#define sz(a) ((int)(a.size()))
#define all(a) a.begin(),a.end()
#define pb(x) push_back(x)
#define endl '\n'
#define debug cerr<<"LINE:     "<<__LINE__<<endl
#define cln cerr<<"LINE:     "<<__LINE__<<"     "
#define pct __builtin_popcountll
#define ctz __builtin_ctzll
#define rep(i,j,k) for(int i=(j);i<=(k);++i)
#define per(i,j,k) for(int i=(j);i>=(k);--i)

using ll=long long; using ull=unsigned long long; using vt=vector<int>;
using vl=vector<ll>; using pii=pair<int,int>; using pll=pair<ll,ll>; using db=double;
constexpr int M=998244353,M1=1e9+7,M2=1e9+9,N=(1<<21)+7,inf=0x3f3f3f3f;
int n,d[__]; ull ans; bool c[__];
namespace math{
    vector<ll>jc,inv,jinv;
    inline void init(int n){
        jc.resize(n+7);
        inv.resize(n+7);
        jinv.resize(n+7);
        jc[0]=jc[1]=1;
        inv[0]=inv[1]=1;
        jinv[0]=jinv[1]=1;
        for(int i=2;i<=n;++i){
            jc[i]=1ll*jc[i-1]*i%M;
            inv[i]=1ll*(M-M/i)*inv[M%i]%M;
            jinv[i]=1ll*jinv[i-1]*inv[i]%M;
        }
    }
    inline ll C(int x,int y){
        if(y<0||x<y) return -1;
        return 1ll*jc[x]*jinv[y]%M*jinv[x-y]%M;
    }
    inline ll P(int x,int y){
        if(y<0||x<y) return -1;
        return 1ll*jc[x]*jinv[x-y]%M;
    }
}
void dfs(int x,int y){
    if(x==n+1&&y<3) return ;
    if(x==n+1&&y>=3){
        int mx=-inf,tot=0;
        for(int i=1;i<=n;++i){
            if(c[i]){
                mx=max(mx,d[i]),tot+=d[i];
            }
        }
        if(tot>mx*2) ++ans;
        return ;
    }
    c[x]=1;
    dfs(x+1,y+1);
    c[x]=0;
    dfs(x+1,y);
}
using namespace math;
signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0);
    int i,j,k,l,r,x,y,z;
    cin>>n; int tot=0;
    if(n>20){
        for(i=1;i<=n;++i) cin>>d[i],tot+=(d[i]==1);
        if(tot!=n){
            cout<<"CSP-S 2025 ++rp!!!"<<endl; 
        }else{
            init(n);
            for(i=3;i<=n;++i){
                ans=(ans+C(n,i))%M;
            }
            cout<<ans%M<<endl;
        }
    }else{
        for(i=1;i<=n;++i) cin>>d[i];
        dfs(1,0); 
        cout<<ans<<endl;
    }
    return 0;
}
// CSP-S 2025,take 200+ score,wish i will!
