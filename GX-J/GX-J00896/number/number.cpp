#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
int main()
{
  freopen("number.in","r",stdin);
  freopen("number.out","w",stdout);
  string s;
  cout<<s;
  int a[10],m=0;
  for(int i=0;i<=1000000;i++)
  {
	for(int n=0;n<=9;n++)
	if(s[i]-'0'==n)
	{
	  a[n]++;
	  m++;
	}  
  }
  for(int i=9;i>=0;i--)
  {
	if(a[i]>0)
	{
	  for(int n=a[i];n>0;n--)
	  cout<<n;
    }
  }
  return 0;
}
