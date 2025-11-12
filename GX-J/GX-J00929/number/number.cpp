#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int main()
{
  freopen("number.in","r",stdin);
  freopen("number.out","w",stdout);
  string s;
  cin>>s;
  int l=s.size(),x=0;
  int a[1000001];
  for(int i=0;i<=l-1;i++)
  {
	if(s[i]-0>=0&&s[i]-0<=57) {x++;a[x]=s[i]-48;}
  }
  for(int i=1;i<=x;i++)
    for(int j=i+1;j<=x;j++)
      if(a[i]<a[j]) swap(a[i],a[j]);
  for(int i=1;i<=x;i++)
    cout<<a[i];
  return 0;	
}
