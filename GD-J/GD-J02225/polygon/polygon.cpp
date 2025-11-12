#include<bits/stdc++.h>
using namespace std;
int n;
const int maxn=5000,moder=998244353;
int a[maxn+5];
const int maxa_i=5000;
long long dp[2*maxa_i+5];
long long pow_2(int n)
{
	long long mul=1,num=2;
	while(n>0)
	{
		if (n&1) mul=(mul*num)%moder;
		num=(num*num)%moder;
		n>>=1;
	}
	return mul;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	long long ans=0;
	memset(dp,0,sizeof dp);
	dp[0]=1;
	for (int i=2;i<=n;i++)
	{
		for (int j=a[n];j>=a[i-1];j--)
		{
			dp[j]=(dp[j]+dp[j-a[i-1]])%moder;
		}
		if (i>=3)
		{
			long long cnt=pow_2(i-1);
			for (int j=0;j<=a[i];j++) cnt=(cnt+moder-dp[j])%moder;
			for (int j=1;j<i;j++) cnt=(cnt+moder-(a[j]>a[i]))%moder;
			ans=(ans+cnt)%moder;
		}
	}
	cout<<ans;
	return 0;
}
