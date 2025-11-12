#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long a[10010],dp[10010];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n;cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long ans=0,limit=0,mx;
	dp[0]=1;
	for(long long i=1;i<=n;i++)
	{
		mx=a[i];ans=(ans+limit)%mod;
		//cout<<ans<<" "<<limit<<" "<<mx<<endl;
		for(long long j=mx+1;j<=5000;j++){
			ans=(ans+dp[j])%mod;
		}
		//cout<<ans<<endl;
		limit=(limit+limit)%mod;
		for(long long j=5000;j>=(5001-mx);j--){
			limit=(limit+dp[j])%mod;
		}
		for(long long j=(5000-mx);j>=0;j--){
			dp[j+mx]=(dp[j+mx]+dp[j])%mod;
		}
//		for(long long j=1;j<=20;j++)
//		{
//			cout<<dp[j]<<" ";
//		}
		
	}
	ans=ans%mod;
	cout<<ans;
	return 0;
} 