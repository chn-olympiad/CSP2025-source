#include<bits/stdc++.h>
#define LL long long
using namespace std;

const LL maxn = 5005, mod = 998244353;
LL n, a[maxn], sum, maxx, ans, dp[maxn][maxn * 2];

int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	if(n <= 20)
	{
		sort(a + 1, a + 1 + n);
		for(int k = 1; k < (1 << n); k++)
		{
			sum = maxx = 0; 
			for(int i = 0; i < n; i++)
			{
				if(k & (1 << i))
				{
					sum += a[i + 1];
					maxx = max(maxx, a[i + 1]); 
				}
			}
			if(sum > 2 * maxx)
				ans = (ans + 1) % mod;
		}
	}
	else if(a[n] == 1)
	{
		
		sort(a + 1, a + 1 + n);
		LL a1, a2, a3;
		a1 = n * (n - 1) * (n - 2) / 6 % mod;
		a2 = (n - 1) * (n - 2) * (n - 3) / 6 % mod;
		a3 = (n - 2) * (n - 3) * (n - 4) / 6 % mod;
		ans = a1 * a2 % mod * a3 % mod;
	}
	else
	{
		dp[0][0] = 1;
		for(int i = 1; i <= n; i++)
		{
			for(int j = 10000; j >= 0; j--)
			{
				dp[i][j] = dp[i - 1][j];
				if(j >= a[i]) dp[i][j] = (dp[i][j] + dp[i - 1][j - a[i]]) % mod; 
			}
		}
		for(int i = 1; i <= n; i++)
			for(int j = 10000; j >= 0; j--)
				dp[i][j] = (dp[i][j] + dp[i][j + 1]) % mod;
				
		for(int i = 1; i <= n; i++)
			ans = (ans + dp[i][2 * a[i] + 1]) % mod;
	}
	cout << ans;
	return 0;
}
