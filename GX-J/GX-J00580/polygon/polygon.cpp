#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,a[5000+10],s[5000+10];
long long ans,x;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	for(int i=1;i<=n;i++)
	{
	  cin>>a[i];
	  s[i]+=s[i-1]+a[i];
	  x+=a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n-2;i++)
	{
	  for(int j=i+1;j<=n-1;j++)
	    for(int k=j+1;k<=n;k++)
	      if(a[i]+a[j]>a[k])
	        ans++;
	}   
	cout<<ans;
	return 0;
}


