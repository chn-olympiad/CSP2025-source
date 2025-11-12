#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  freopen("club.in","r",stdin);
  freopen("club.out","w",stdout);
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int t; cin>>t;
  while(t--){
    int n; cin>>n;
    vector<vector<int> > a(n,vector<int>(3));
    for(auto &i:a)for(auto &j:i)cin>>j;
    vector<int> w(n),c(3);
    ll r=0;
    for(int i=0;i<n;i++){
      c[w[i]=max_element(a[i].begin(),a[i].end())-a[i].begin()]++;
      r+=a[i][w[i]];
    }
    int m=max_element(c.begin(),c.end())-c.begin();
    if(c[m]>n/2){
      vector<int> v;
      for(int i=0;i<n;i++)
        if(w[i]==m){
          int mx=0;
          for(int j=0;j<3;j++)
            if(j!=m)mx=max(mx,a[i][j]);
          v.emplace_back(a[i][m]-mx);
        }
      sort(v.begin(),v.end());
      for(int i=0;i<c[m]-n/2;i++)
        r-=v[i];
    }
    cout<<r<<'\n';
  }
  return 0;
}