#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,c[505],f[262144][20],ans;
char s[505];
namespace subtask12_14{
  int cnt[505];
  void solve(){
    for(int i=1;i<=n;i++){
      if(s[i]=='1')cnt[i-1]++;
      else cnt[n]++;
    }
    sort(c+1,c+n+1);
    int ans=1,fac=1;
    for(int i=n,j=n+1,num=0;i>=1;i--){
      while(j>c[i])num+=cnt[--j];
      ans=1ll*ans*num%mod,num--;
    }
    for(int i=1;i<=n;i++)fac=1ll*fac*i%mod;
    cout<<(fac-ans+mod)%mod<<'\n';
  }
}
namespace subtask15{
  void solve(){
    for(int i=1;i<=n;i++){
      if(s[i]=='0'||!c[i]){
        cout<<0<<'\n';
        return;
      }
    }
    int ans=1;
    for(int i=1;i<=n;i++)ans=1ll*ans*i%mod;
    cout<<ans<<'\n';  
  }
}
int main(){
  freopen("employ.in","r",stdin);
  freopen("employ.out","w",stdout);
  f[0][0]=1,cin>>n>>m>>s+1;
  for(int i=1;i<=n;i++)cin>>c[i];
  if(m==n)return subtask15::solve(),0;
  if(m==1)return subtask12_14::solve(),0;
  for(int i=1;i<1<<n;i++){
    int num=__builtin_popcount(i);
    for(int j=0;j<num;j++){
      for(int k=0;k<n;k++){
        if(~i>>k&1)continue;
        bool type=s[num]=='1'&&c[k+1]>num-j-1;
        f[i][j+type]=(f[i][j+type]+f[i^(1<<k)][j])%mod;
      }  
    }
  }
  for(int i=m;i<=n;i++)ans=(ans+f[(1<<n)-1][i])%mod;
  return cout<<ans<<'\n',0;
}
