#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define pb push_back
#define rep(x,y,z) for(int x=y;x<z;x++)
#define cin fin
#define cout fout
ifstream fin("employ.in");
ofstream fout("employ.out");
const int mod=998244353;

signed main(){
  cin.tie(nullptr)->ios::sync_with_stdio(0);
  int n,m;
  cin>>n>>m;
  char c;
  vector<bool> vis(n);
  rep(i,0,n){
      cin>>c;
      vis[i]=(c=='1');
  }
  vector<int> arr(n);
  rep(i,0,n){
      cin>>arr[i];
  }
  int ful=(1<<n);
  int dp[ful][n+1];
  rep(i,0,ful) rep(j,0,n+1) dp[i][j]=0;
  dp[0][0]=1;
  rep(i,0,ful-1){
      int cnt=0;
      rep(j,0,n){
          if (i&(1<<j)) cnt++;
      }
      rep(j,0,n+1){
          if (dp[i][j]==0) continue;
          rep(h,0,n){
              if (!(i&(1<<h))){
                  if (vis[cnt]==0||arr[h]<=j){ //not accept
                    if (j+1<=n) dp[i+(1<<h)][j+1]+=dp[i][j];
                        dp[i+(1<<h)][j+1]%=mod;
                  }else{
                      dp[i+(1<<h)][j]+=dp[i][j];
                        dp[i+(1<<h)][j]%=mod;
                  }
              }
          }
        //   bitset<3> bit(i);
        //   cout<<bit.to_string()<<", "<<j<<": "<<dp[i][j]<<'\n';
      }
  }
  int ans=0;
  rep(i,0,n-m+1){
      ans+=dp[ful-1][i];
      ans%=mod;
  }
  cout<<ans;
  return 0;
}
