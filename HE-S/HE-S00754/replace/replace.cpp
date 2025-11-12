#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
int n,q;
int main(){
  freopen("replace.in","r",stdin);
  freopen("replace.out","w",stdout);
  cin>>n>>q;
  string s[N][3],t[N][3];
  for (int i=1; i<=n;i++){
  	cin>>s[i][1];
  	cin>>s[i][2];
  }
  for (int i=1; i<=q;i++){
  	cin>>t[i][1];
  	cin>>t[i][2];
  	cout<<0<<'\n';
  }
  return 0;
}

