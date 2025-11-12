#include<bits/stdc++.h>
using namespace std;
#define reg register
#define _ 57
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
int d[_],n,m,a[__],ans;
signed main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0);
    int i,j,k,l,r,x,y,z;
    cin>>n>>m; set<int>st;
    for(i=1;i<=n;++i) cin>>a[i];
    l=1,r=1,x=0; // debug;
    for(;l<=n&&r<=n;++r){
        x^=a[r];
        if(a[r]==m){
            l=r+1,++ans,x=0; st.clear();
        }
        else{
            k=x^m;
            if(st.find(k)!=st.end()){
                ++ans,l=r+1; x=0,st.clear();
            }
            else if(x==m){
                ++ans,l=r+1; x=0,st.clear();
            }
            else st.insert(x);
        }
    }cout<<ans<<endl;
    return 0;
}
// CSP-S 2025 unsigned long long rp=-1!!!
