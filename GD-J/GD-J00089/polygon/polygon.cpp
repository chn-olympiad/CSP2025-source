#include <iostream>
#include <algorithm>
#include <cstdio>

#define int long long

using namespace std ;

const int N = 5e3 + 5, M = 5e4 + 5, MOD = 998244353 ;

int n, a[N], S[N] ;
int dp[505][M] ;

int C(int na, int m)
{
	if (m > na - m)
	{
		int res = 1 ;
		for (int i = m + 1 ; i <= na ; i ++ )
			res = res * i % MOD ;
		return res ;
	}
	else
	{
		int res = 1 ;
		for (int i = na - m + 1 ; i <= na ; i ++ )
			res = res * i % MOD ;
		return res ;
	}
	
}

int Max, res ;

void dfs(int cur, int sum, int maxi)
{
	if (cur == n + 1)
	{
		if (sum > maxi * 2)
			res ++  ;
		return ;
	}
	
	if (maxi * 2 >= S[n] - S[cur - 1] + sum)
		return ;
	
	dfs(cur + 1, sum + a[cur], max(maxi, a[cur])) ;
	dfs(cur + 1, sum, maxi) ;
}

signed main()
{
	freopen("polygon.in", "r", stdin) ;
	freopen("polygon.out", "w", stdout) ;
	
	cin >> n ;
	for (int i = 1 ; i <= n ; i ++ )
		cin >> a[i], Max = max(Max, a[i]) ;
	
	sort(a + 1, a + n + 1), reverse(a + 1, a + n + 1) ;
	if (Max == 1)
	{
		res = 0 ;
		for (int i = 3 ; i <= n ; i ++ )
			res = (res + C(n, i)) % MOD ;
	}
	else if (Max <= 100)
	{
		reverse(a + 1, a + n + 1) ;
		for (int i = 1 ; i <= n ; i ++ )
			S[i] = S[i - 1] + a[i] ;
		for (int i = 1 ; i <= n ; i ++ )
			for (int j = i + 1 ; j <= n ; j ++ )
				dp[2][a[i] + a[j]] = 1 ;
		for (int i = 3 ; i <= n ; i ++ )
			for (int j = 2 * a[i] + 1 ; j <= S[n] ; j ++ )
			{
				dp[i][j] = dp[i - 1][j] ;
				if (j - a[i] >= 2 * a[i - 1])
					dp[i][j] = dp[i - 1][j - a[i]] + 1 ;
				if (i == 3)
					dp[i][j] = dp[i - 1][j - a[i]] ;
			}
		for (int i = S[3] ; i <= S[n] ; i ++ )
			res += dp[n][i] ;
	}
	else
	{
		for (int i = 1 ; i <= n ; i ++ )
			S[i] = S[i - 1] + a[i] ;
		dfs(1, 0, 0) ;
	}
	
	cout << res << '\n' ;
	
	return 0 ;
}
