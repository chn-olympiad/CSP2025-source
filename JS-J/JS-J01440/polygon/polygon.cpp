#include<bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define mod 998244353
int n, a[5005];
int ans;
int smx;
void dfs(int p, int sum, int mx, int cnt)
{
	if(p == n+1)
	{
		if(cnt >= 3 && sum > 2*mx)
			ans= (ans+1)%mod;
		return;
	}
	dfs(p+1, sum, mx, cnt);
	dfs(p+1, sum+a[p], max(mx, a[p]), cnt+1);
}
int c[5005][5005];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	mt19937 rng((unsigned long long)(new char));
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 0;i <= 5001;i++)
		c[i][0] = c[i][i] = 1;
	for(int i = 2;i <= 5000;i++)
	{
		for(int j = 1;j < i;j++)
			c[i][j] = (c[i-1][j] + c[i-1][j-1]) % mod;
	}
	for(int i = 1;i <= n;i++)
	{
			cin >> a[i];
			smx = max(smx, a[i]);
	}
	if(smx == 1)
	{
		for(int i = 3;i <= n;i++)
		{
			ans = (ans + c[n][i]) % mod;
		}
	}
	else
		dfs(1,0, 0, 0);
	cout << ans << endl;
	return 0;
}
