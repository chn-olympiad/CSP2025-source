#include <bits/stdc++.h>
using namespace std;
int t=0;
string str;
char a[10000001];
int main()
{
  freopen("number.in","r",stdin);
  freopen("number.out","w",stdout);
  cin>>str;
  int ll=str.size();
  for(int i=0; i<ll;i++)if(str[i]>='0' and str[i]<='9')a[++t]=str[i];
  sort(a+1,a+1+t);
  if(a[t]=='0')cout<<0;
  else for(int i=t;i>0;i--)cout<<a[i];
  return 0;
}
