#include<bits/stdc++.h>
using namespace std;
#define reg register
#define _ 27
#define __ 1007
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
int n,m,s[__]; pii g[__];
signed main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0);
    int i,j,k,l,r,x,y,z;
    cin>>n>>m;
    y=0;
    for(i=1;i<=n*m;++i) cin>>s[i]; x=s[1];
    stable_sort(s+1,s+n*m+1,[](int tx,int ty){ return tx>ty; });
    for(j=1;j<=m;++j){
        if(j%2==0){
            for(i=n;i>=1;--i) g[s[++y]].first=i,g[s[y]].second=j;
        }else{
            for(i=1;i<=n;++i) g[s[++y]].first=i,g[s[y]].second=j;
        }
    }
    cout<<g[x].second<<" "<<g[x].first<<endl;
    return 0;
}
// very good problem,love from some freaky IDEA
