#include<bits/stdc++.h>
using namespace std;

string a,b;

int main()
{
  freopen("number.in","r",stdin);
  freopen("number.out","w",stdout);
  cin.tie(0)->sync_with_stdio(0);
  cin>>a;
  for(auto &c:a)
    if(isdigit(c))
      b+=c;
  sort(b.begin(),b.end(),[](char &a,char &b){return a>b;});
  cout<<b<<endl;
  return 0;
}
