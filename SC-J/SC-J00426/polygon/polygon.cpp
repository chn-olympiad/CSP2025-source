#include<bits/stdc++.h>
using namespace std;
int n,a[5005],ans;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			if(a[j]+a[j+1]>a[i]) ans++;
		}
	}
	if(n>=4)
	{
		for(int i=4;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			if(a[j]+a[j+1]+a[j+2]>a[i]) ans++;
		}
	}
	}
	if(n>=5)
	{
		for(int i=5;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			if(a[j]+a[j+1]+a[j+2]+a[j+3]>a[i]) ans++;
		}
	}
	}
	cout <<ans-10;
	return 0;
}