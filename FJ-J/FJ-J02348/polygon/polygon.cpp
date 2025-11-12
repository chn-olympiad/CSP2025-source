#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int dp[5005];
int l[5005];
int n;
int main(){
	
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	cin>>n;
	int i,j;
	for(i=1;i<=n;i++)
	{
		cin>>l[i];
	}
	sort(l+1,l+n+1);
	dp[0]=1;
	int ans=0;
	for(i=1;i<=n;i++)
	{
		for(j=l[i]+1;j<=5001;j++)
		{
			ans=(ans+dp[j])%mod;
		}
		dp[5001]=dp[5001]*2%mod;
		for(j=5000-l[i]+1;j<=5000;j++)
		{
			dp[5001]=(dp[5001]+dp[j])%mod;
		}
		for(j=5000-l[i];j>=0;j--)
		{
			dp[j+l[i]]=(dp[j+l[i]]+dp[j])%mod;
		}
	}
	cout<<ans;
	
	return 0;
} 
