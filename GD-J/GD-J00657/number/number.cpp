#include<bits/stdc++.h>
// #define int long long
using namespace std;

string s;
vector<char> a;

signed main(){
  freopen("number.in","r",stdin);
  freopen("number.out","w",stdout);

  // clock();

  ios::sync_with_stdio(0);cin.tie(0);

  cin>>s;

  for(char c:s){
    if(c>='0' && c<='9'){
      a.push_back(c);
    }
  }

  sort(a.begin(),a.end());
  reverse(a.begin(),a.end());

  for(char c:a){
    cout<<c;
  }

  // cout<<'\n';
  // cout<<clock();

}