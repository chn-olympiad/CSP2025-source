#include<bits/stdc++.h>
#define int long long
using std::cin;
using std::cout;
using std::min;
using std::max;
using std::sort;
using std::memset;
using std::vector;
using std::set;
using std::ios;

int n,a[3][1000005],b[1000005],c[1000005];
void solve(){
  cin>>n;
  int ans=0,cnt[3]={0,0,0};
  for (int i=1;i<=n;i++){
    cin>>a[0][i]>>a[1][i]>>a[2][i];
    if (a[0][i]>=a[1][i]&&a[0][i]>=a[2][i]){
      ans+=a[0][i];
      b[i]=0;
      cnt[0]++;
      c[i]=a[0][i]-max(a[1][i],a[2][i]);
    }
    else if (a[1][i]>=a[0][i]&&a[1][i]>=a[2][i]){
      ans+=a[1][i];
      b[i]=1;
      cnt[1]++;
      c[i]=a[1][i]-max(a[0][i],a[2][i]);
    }
    else{
      ans+=a[2][i];
      b[i]=2;
      cnt[2]++;
      c[i]=a[2][i]-max(a[0][i],a[1][i]);
    }
  }
  for (int i=0;i<3;i++){
    if (cnt[i]>n/2){
      int x=cnt[i]-n/2;
      vector<int> v;
      for (int j=1;j<=n;j++){
	if (b[j]==i){
	  v.push_back(c[j]);
	}
      }
      sort(v.begin(),v.end());
      for (int j=0;j<x;j++){
	ans-=v[j];
      }
      cout<<ans<<"\n";
      return;
    }
  }
  cout<<ans<<"\n";
  return;
}

signed main(){
  freopen("club.in","r",stdin);
  freopen("club.out","w",stdout);
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int t;cin>>t;
  while (t--)solve();
  return 0;
}
