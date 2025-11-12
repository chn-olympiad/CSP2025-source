#include<bits/stdc++.h>
using namespace std;
long long a[10000000];
int main()
{
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
string s;
cin>>s;
for(long long i=0;i<s.size();i++)
{

  if(s[i]>='1'&&s[i]<='9')
  {
  cout<<s[i];
  }
}
return 0;
}
