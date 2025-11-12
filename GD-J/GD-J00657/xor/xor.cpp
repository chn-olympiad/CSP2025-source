#include<bits/stdc++.h>
// #define int long long
using namespace std;

int n,k,ans;
int a[500005];

unordered_map<int,int> mp;

signed main(){
  freopen("xor.in","r",stdin);
  freopen("xor.out","w",stdout);
  ios::sync_with_stdio(0);cin.tie(0);

  cin>>n>>k;

  for(int i=1;i<=n;i++){
    cin>>a[i];
  }

  mp[0]=1;

  for(int i=1;i<=n;i++){
    int x=(a[i]^a[i-1]);
    if(mp[x^k]){
      mp.clear();
      mp[0]=1;
      a[i]=0;
      ans++;
    }
    else{
      a[i]=x;
      mp[a[i]]=1;
    }
  }

  cout<<ans<<'\n';

}