#include <bits/stdc++.h>
using namespace std;
int n=0,k=0,s;
long long a[100005];
bool cmp(int a,int b)
{
   return a>=b;
}
int main
{
   freopen("number.in","r",stdin);
   freopen("number.out","w",stdout);
   cin>>n;
   s=n;
   while(n>=0)
   {
      if(n>=0 && n<=9)
      {
           cout<<n;
	   break;
      }
      else
      {
	   k++;
	   n/=10;
      }
  }
	for(int i=1;i<=k+1;i++)
	{
	   s/=10;
	   a[i]=s%10;
	}
	sort(a+1,a+k+1,cmp);
	for(int i=1;i<=k+1;i++)
	{
	   cout<<a[i];
	}
	return 0;
