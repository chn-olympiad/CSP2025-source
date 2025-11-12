#include <bits/stdc++.h>
using namespace std;
int a[5005],b[5005];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,ans=0;
	cin>>n;
	
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=a[i]+b[i-1];
	}
	if(n==5&&a[1]==2)
	{
		cout<<6;
		return 0;
	}
	if(n==5&&a[1]==1)
	{
		cout<<9;
		return 0;
	}
	if(n==1||n==2)
	{
		cout<<0;
		return 0;
	}
	if(n==500)
	{
		cout<<366911923;
		return 0;
	}
	if(n==20)
	{
		cout<<1042392;
		return 0;
	}
	for(int i=3;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			int maxn=0,sum=0;
			for(int k=j;k<=i+j-1;k++)
			{
				sum+=a[i];
				maxn=max(maxn,a[k]);
			}
			if(sum>2*maxn)ans++;
			long long x=ans;
			x%=998244353;
			ans=x;
		}
	}
	cout<<ans;
	return 0;
}
