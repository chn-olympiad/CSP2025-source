#include <bits/stdc++.h>
using namespace std;
long long n,a[5005],dp[5005][5005];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for (int i=1;i<=n;i++) cin >> a[i];
	sort(a+1,a+1+n);
	dp[1][0]=1;
	for (int i=0;i<=a[1];i++) dp[1][i]++;
	for (int i=2;i<=n;i++) dp[i][0]=dp[i-1][0]*2%998244353;
	for (int i=2;i<=n;i++)
	{
		for (int j=1;j<=a[n]+1;j++) dp[i][j]=(dp[i-1][max(0ll,j-a[i])]+dp[i-1][j])%998244353;
	}
	long long ans=0;
	for (int i=n;i>=1;i--)
	{
		ans+=dp[i-1][a[i]+1];
		ans%=998244353;
	}
	cout << ans;
	return 0;
}
