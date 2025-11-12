#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MOD=998244353;

int n,m,ans;
int c[501];

string s;

int a[11];

int fc(int n){
  int res=1;
  for(int i=1;i<=n;i++) res=(res*i)%MOD;
  return res;
}

signed main(){
  freopen("employ.in","r",stdin);
  freopen("employ.out","w",stdout);
  ios::sync_with_stdio(0);cin.tie(0);

  cin>>n>>m;

  cin>>s;

  if(n>10){
    for(int i=1;i<=n;i++){
      cin>>c[i];
      if(s[i]=='0' || c[i]==0){
        cout<<0;
        return 0;
      }
    }
    sort(c+1,c+n+1);
    reverse(c+1,c+n+1);

    cout<<fc(n)<<'\n';

    return 0;
  }

  for(int i=1;i<=n;i++){
    cin>>c[i];
    a[i]=i;
  }

  do{
    int cnt=0;
    for(int i=1;i<=n;i++){
      if(cnt>=c[a[i]] || s[i-1]=='0'){
        cnt++;
      }
    }

    // cout<<cnt<<'\n';

    if(n-cnt>=m){
      ans=(ans+1)%MOD;
    }

  }while(next_permutation(a+1,a+n+1));

  cout<<ans<<'\n';

}