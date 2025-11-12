#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e3 + 10, mod = 998244353;

int a[N], dp[510][52001], sum[510][52000];
int n, k;

int qpow(int a, int k)
{
	int res = 1;
	while(k)
	{
		if(k & 1)
			res = res * a % mod;
		a = a * a % mod;
		k >>= 1;
	}
	return res;
}

signed main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	bool flag = 0;
	int S = 0;
	for(int i = 1; i <= n; i ++ )
		cin >> a[i], flag |= (a[i] != 1), S += a[i];	
	int ans = 0;
	if(n <= 20)
	{
		for(int i = 0; i < (1 << n); i ++ )
		{
			int sum = 0, maxx = 0, cnt = 0;
			for(int j = 0; j < n; j ++ )
				if(((i >> j) & 1) == 1)
				{
					cnt ++ ;
					sum += a[j + 1];
					maxx = max(maxx, a[j + 1]);
				}
			if(cnt <= 2)
				continue;
			if(sum > 2 * maxx)
				ans ++ ;
		}
		cout << ans << endl;
	}
	else if(!flag)
	{
		int a = qpow(2, n) % mod;
		int b = n % mod * (n - 1) % mod * qpow(2, mod - 2) % mod;
		int c = n % mod;
		cout << (((a - b + mod) % mod - c + mod) % mod - 1 + mod) % mod;
	}
	else
	{
		sort(a + 1, a + n + 1);
		for(int i = 1; i <= n; i ++ )
			dp[i][a[i]] = 1;
		for(int i = 1; i <= n; i ++ )
		{
			for(int j = 1; j <= S; j ++ )
			{
				if(j < a[i])
					dp[i][j] = dp[i - 1][j];
				else
					dp[i][j] = ((dp[i][j] % mod + dp[i - 1][j]) % mod + dp[i - 1][j - a[i]]) % mod;
				sum[i][j] = (sum[i][j - 1] + dp[i][j]) % mod;
			}
		}
		for(int i = 1; i <= n; i ++ )
		{
			ans = ((ans + sum[i - 1][S]) % mod - sum[i - 1][a[i]] + mod) % mod;
			int sums = 0;
			for(int j = 1; j < i; j ++ )
				if(a[j] > a[i])
					sums ++ ;
			ans = (ans - sums + mod) % mod;
		}	
		cout << ans << endl;
	}
	return 0;
}
