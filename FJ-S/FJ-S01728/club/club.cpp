#include <bits/stdc++.h>
using namespace std;
int T,n,a[100010][5],ans,mx;
int dp[505][505];
int dp2[50010];
void solve1()
{
	ans = 0;
	for(int i=1; i<=n; i++)
	{
		cin >> a[i][1] >> a[i][2] >> a[i][3];
		ans += a[i][1];
		a[i][2] -= a[i][1];
		a[i][3] -= a[i][1];
	}
	memset(dp,0xc0c0c0c0,sizeof(dp));
	dp[0][0] = 0;
	for(int i=1; i<=n; i++)
	{
		for(int j=n/2; j>=0; j--)
		{
			for(int k=n/2; k>=0; k--)
			{
				if(j) dp[j][k] = max(dp[j][k],dp[j-1][k]+a[i][2]);
				if(k) dp[j][k] = max(dp[j][k],dp[j][k-1]+a[i][3]);
			}
		}
	}
	mx = 0xc0c0c0c0;
	for(int j=0; j<=n/2; j++)
	{
		for(int k=n/2-j; k<=n/2; k++)
		{
			mx = max(mx,dp[j][k]);
		}
	}
	cout << ans+mx << '\n';
}
void solve2()
{
	ans = 0;
	for(int i=1; i<=n; i++)
	{
		cin >> a[i][1] >> a[i][2] >> a[i][3];
		ans += a[i][1];
		a[i][2] -= a[i][1];
	}
	memset(dp2,0xc0c0c0c0,sizeof(dp2));
	dp2[0] = 0;
	for(int i=1; i<=n; i++)
	{
		for(int j=min(n/2,i); j>=max(i,n/2-i); j--)
		{
			dp2[j] = max(dp2[j],dp2[j-1]+a[i][2]);
		}
	}
	cout << ans+dp2[n/2] << '\n';
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	
	cin >> T;
	while(T--)
	{
		cin >> n;
		if(n <= 200) solve1();
		else solve2();
	}
	return 0;
}
