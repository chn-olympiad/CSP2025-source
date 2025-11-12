#include<bits/stdc++.h>
using namespace std;
#define reg register
#define _ 27
#define __ 10007
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
string a; int d[__];
signed main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0);
    int i,j,k,l,r,x,y,z;
    cin>>a;
    l=a.size();
    for(i=0;i<l;++i) if(a[i]>='0'&&a[i]<='9') d[a[i]-'0']++;
    for(i=9;i>=0;--i) for(j=1;j<=d[i];++j) cout<<i;
    cout<<endl;
    return 0;
}
// CCF I Love you!!!
// I am Zyhx,bx luotianyi & yuezhenglin & yanhe
