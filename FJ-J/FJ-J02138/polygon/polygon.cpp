#include<bits/stdc++.h>
using namespace std;
int a[5050];
long long dp[5050],cnt[5050];
long long mod=998244353,ans=1,sum=1;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	dp[0]=1;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		cnt[a[i]]++;
		ans*=2;
		ans%=mod;
	}
	ans--;
	for(int i=1;i<=n;i++)
	{
		for(int j=5005;j>=a[i];j--)
		{
			dp[j]+=dp[j-a[i]];
			dp[j]%=mod;
		}
	}
	for(int i=1;i<=5005;i++)
	{
		sum+=dp[i];
		sum%=mod;
		ans-=(cnt[i]*(sum-1)-cnt[i]*(cnt[i]-1)/2);
		ans=(ans%mod+mod)%mod;
	}
	cout<<ans;
	return 0;
}
