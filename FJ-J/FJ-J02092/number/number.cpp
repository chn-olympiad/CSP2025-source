#include<bits/stdc++.h>
using namespace std;
namespace leo {
  string s;
  vector<char> num;
  void main() {
    freopen("number.in","r",stdin);
    freopen("number.out","w+",stdout);
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin>>s;
    for(int i=0;i<s.length();i++)
      if(isdigit(s[i]))
        num.emplace_back(s[i]);
    sort(num.begin(),num.end());
    reverse(num.begin(),num.end());
    for(int i=0;i<num.size();i++)
      cout<<num[i];
    cout<<'\n';
  }
}
int main() {
  leo::main();
}

