#include<bits/stdc++.h>
using namespace std;
const int N=5140,mod=998244353;
int dp[N],a[N],n,sum[N],pw[N];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	dp[0]=1;pw[0]=1;
	for(int i=1;i<=n;i++)
	{
		pw[i]=(pw[i-1]*2)%mod;
		sum[i]=pw[i-1]-1;
		for(int j=1;j<=a[i];j++) sum[i]=(sum[i]-dp[j])%mod;//,cout<<i<<' '<<j<<' '<<dp[j]<<endl;
		sum[i]=(sum[i]+mod)%mod;
		for(int j=5000;j>=a[i];j--) dp[j]=(dp[j]+dp[j-a[i]])%mod;
	}
	int ans=0;
	for(int i=1;i<=n;i++) ans=(ans+sum[i])%mod;//,cout<<sum[i]<<endl;
	cout<<ans;
 }

