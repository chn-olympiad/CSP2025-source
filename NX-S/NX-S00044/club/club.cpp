// CSPS2025 - club
// Alea(322792)
#include <bits/stdc++.h>
using namespace std;
ifstream fin("club.in");
ofstream fout("club.out");
// only for 75%
typedef long long ll;
const int N=1e5+5;
const ll inf=0x3f3f3f3f3f3f3f3f;
int n;
struct wh{
    ll a,b,c;
}a[N];
map<pair<int,pair<int,int>>,ll> memo;
ll dp(int x,int A,int B,int dep=0){
    if(memo.count({x,{A,B}})) return memo[{x,{A,B}}];
    ll &ans=memo[{x,{A,B}}]=-inf;
    if(A+B<=x-1) ans=max(ans,dp(x-1,A,B,dep+1)+a[x].c);
    if(A>0) ans=max(ans,dp(x-1,A-1,B,dep+1)+a[x].a);
    if(B>0) ans=max(ans,dp(x-1,A,B-1,dep+1)+a[x].b);
    return ans;
}
ll solve(){
    bool c0=1;
    fin>>n,n/=2;
    for(int i=1;i<=2*n;++i){
        fin>>a[i].a>>a[i].b>>a[i].c;
        c0&=(a[i].c==0);
    }
    memo.clear(),memo[{0,{0,0}}]=0;
    if(c0) return dp(n*2,n,n);
    else{
        ll ans=-inf;
        for(int i=n;i>=0;--i) for(int j=(n<<1)-i;j>=0;--j)
            if(i<=n&&j<=n&&i+j>=n) ans=max(ans,dp(2*n,i,j));
        return ans;
    }
}
int main(){
    int _;
    fin>>_;
    while(_--) fout<<solve()<<endl;
    return 0;
}