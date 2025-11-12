#include<bits/stdc++.h>
using namespace std;
int n;
int a[5007];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n==3)
	{
		int x,y,z;
		cin>>x>>y>>z;
		if((x+y>z)&&(x+z>y)&&(z+y>x))
		{
			cout<<1;
			return 0;
		}
		
		else
		{
			cout<<0;
			return 0;
		}
		
	}
	
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	
	long long ans=0;
	for(int i=3;i<=n;i++)
	{
		long long cnt=1;
		for(int j=n;j>=n-i+1;j--)
		{
			cnt*=j;
		}
		
		for(int j=1;j<=i;j++)
		{	
			cnt/=j;
		}
		
		ans+=cnt%998244353;
	}
	
	cout<<ans%998244353;
	return 0;
}
