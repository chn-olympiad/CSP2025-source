#include<bits/stdc++.h>
using namespace std;
int const N=1000005;
string s;
int a[N];
int main()
{
  freopen("number.in","r",stdin);
  freopen("number.out","w",stdout);
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>s;
  for(int i=0;i<=s.size()-1;i++)
  {
  	if(int(s[i])>=48&&int(s[i])<=57)
  	a[int(s[i]-48)]++;
  }
  for(int j=9;j>=0;j--)
 for(int i=1;i<=a[j];i++)
  cout<<j;
  return 0;
}

