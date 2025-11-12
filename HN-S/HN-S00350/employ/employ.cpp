#include<bits/stdc++.h>
using namespace std;
using ll =long long;
using ull = unsigned long long;
using pll = pair<ll,ll>;
using pii = pair<int,int>;
using ar3 = array<int,3>;
#define fi first
#define se second
#define ep emplace
#define eb emplace_back
#define all(x) x.begin(),x.end()
#define ffor(i,l,r) for(int i=(l),_=(r);i<=_;i++)
#define rfor(i,r,l) for(int i=(r),_=(l);i>=_;i--)
constexpr int N=550;
constexpr int SZ=1e6;
constexpr int mod = 998244353;
char ti[N];
int n,m,c[N],f[SZ][20];
int main(){
  cin.tie(0)->ios::sync_with_stdio(0);
  freopen("employ.in","r",stdin);
  freopen("employ.out","w",stdout);
  cin>>n>>m>>(ti+1);
  ffor(i,0,n-1)cin>>c[i];
  f[0][0]=1;
  ffor(s,1,(1<<n)-1){
    int num=__builtin_popcount(s);
    ffor(i,0,n-1){
      ffor(j,0,n-1){
        if(num-1-j>=c[i]||ti[num]=='0')(f[s][j]+=f[s^1<<i][j])%=mod;
        else (f[s][j+1]+=f[s^1<<i][j])%=mod;
      }
    }
  }
  ll ans=0;
  ffor(i,m,n)(ans+=f[(1<<n)-1][i])%=mod;
  cout<<ans;
  return 0;
}
//g++ -O2 code.cpp -o code -std=c++14 -Wall -Wextra -fsanitize=address,leak,undefined && time ./code 