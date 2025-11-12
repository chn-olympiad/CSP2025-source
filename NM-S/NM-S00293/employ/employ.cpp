// shinzanmonoWYB@hs2z
#include<iostream>
#include<algorithm>
using ll=long long;
const int sz=510;
const ll mod=998244353;
void file(std::string s){
  freopen((s+".in").c_str(),"r",stdin);
  freopen((s+".out").c_str(),"w",stdout);
}
int a[sz];
ll f[1<<18][20];
ll fact(int n){
  if(n<=1)return 1;
  return n*fact(n-1)%mod;
}
int main(){
  file("employ");
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n,m;
  std::string s;
  std::cin>>n>>m>>s,s=" "+s;
  for(int i=1;i<=n;i++)std::cin>>a[i];
  if(m==n)std::cout<<(std::count(s.begin(),s.end(),'0')==0&&std::count(a+1,a+n+1,0)==0?fact(n):0)<<"\n",exit(0);
  f[0][0]=1;
  for(int i=0;i<1<<n;i++){
    for(int j=0;j<=__builtin_popcount(i);j++){
      for(int k=1;k<=n;k++){
        if(i>>k-1&1)continue;
        if(s[__builtin_popcount(i)+1]=='1'&&a[k]>j)
          f[i|(1<<k-1)][j]=(f[i|(1<<k-1)][j]+f[i][j])%mod;
        else f[i|(1<<k-1)][j+1]=(f[i|(1<<k-1)][j+1]+f[i][j])%mod;
      }
    }
  }
  ll ans=0;
  for(int i=0;i<=n-m;i++)ans=(ans+f[(1<<n)-1][i])%mod;
  std::cout<<ans<<"\n";
  return 0;
}