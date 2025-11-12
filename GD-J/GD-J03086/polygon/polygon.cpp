#include<bits/stdc++.h>
using namespace std;
long long n,a[5010],dp[5010],c[5010],mod=998244353;
int main(){
	
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	c[a[1]]++;
	c[a[2]]++;
	if(a[1]+a[2]>5000)
	{
		c[5001]++;
	}
	else
	c[a[1]+a[2]]++;
	for(int i=3;i<=n;i++)
	{
		long long t=0;
		for(int j=a[i]+1;j<=5001;j++)
		{
			t+=c[j];
			t%=mod;
		}
		dp[i]+=t;
		dp[i]%=mod;
		c[5001]+=c[5001];
		c[5001]%=mod;
		for(int j=5000;j>=a[i]+1;j--)
		{
			if(j+a[i]>5000)
			{
				c[5001]+=c[j];
				c[5001]%=mod;
			}
			c[j]+=c[j-a[i]];
			c[j]%=mod;
		}
		c[a[i]]++;
		c[a[i]]%=mod;
	}
	long long ans=0;
	for(int i=1;i<=n;i++)
	{
		ans+=dp[i];
		ans%=mod;
	}
	cout<<ans%mod;
	return 0;
}

