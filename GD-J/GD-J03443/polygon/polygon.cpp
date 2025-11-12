#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],dp[5005],sum,s,fa[5005],mod=998244353;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	fa[3]=1;
	for(int i=4;i<=n;i++)
	{
		fa[i]=((fa[i-1]+mod-fa[i-2])%mod)*2+(i-2)+fa[i-1];
		fa[i]%=mod;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	dp[0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=5000;j>=a[i];j--)
		{
			dp[j]+=dp[j-a[i]];
		}
	}
	for(int i=1;i<=n;i++)
	{
		dp[a[i]]--;
	}
	sort(a+1,a+1+n);
	for(int i=3;i<=n;i++)
	{
		for(int j=a[i];j>=1;j--)
		{
			sum+=dp[j];
			sum=sum%mod;
		}
	}
	cout<<(fa[n]-sum+mod)%mod;
	
	
	return 0;
}
