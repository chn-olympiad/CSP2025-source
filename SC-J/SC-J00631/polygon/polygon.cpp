#include<bits/stdc++.h>
using namespace std;

int n,a[5003];
long long ans=0,mod=998244353;

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int f1=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]>1)
			f1=0;
	}
	sort(a+1,a+n+1);
	if(n==3)
	{
		if(a[1]+a[2]<=a[3])
			cout<<0;
		else
			cout<<1;
		return 0;
	}
	if(f1==1)
	{
		for(int i=3;i<=n;i++)
		{
			long long cur=1;
			for(int j=n;j>=n-i+1;j--)
				cur*=j;
			for(int j=i;j>=1;j--)
				cur/=j;
			ans+=(ans+cur)%mod;
		}
		cout<<ans;
		return 0;
	}
	
	return 0;
}