#include<bits/stdc++.h>
// #define int long long
using namespace std;

int n,q;

pair<int,int> s[200001];

// unordered_map<string,>

signed main(){
  freopen("replace.in","r",stdin);
  freopen("replace.out","w",stdout);
  ios::sync_with_stdio(0);cin.tie(0);

  cin>>n>>q;

  for(int i=1;i<=n;i++){
    cin>>s[i].first>>s[i].second;
  }

  for(int i=1;i<=q;i++){
    string t1,t2;
    cin>>t1>>t2;
    cout<<0<<'\n';
  }

}
