#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef unsigned int UI;
typedef unsigned long long ULL;

typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
#define x first
#define y second

const int N = 5005;
const LL MOD = 998244353;

int n, a[N];

LL pw[N];
LL dp[N][N];
LL res;

int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	cin >> n;
	for (int i = 1; i <= n; i ++ ) cin >> a[i];
	
	sort(a + 1, a + n + 1);
	
	pw[0] = 1;
	for (int i = 1; i <= n; i ++ ) pw[i] = pw[i - 1] * 2 % MOD;
	dp[0][0] = 1;
	for (int i = 1; i <= n; i ++ )
	{
		dp[i][0] = pw[i];
		for (int j = 1; j <= 5000; j ++ )
			dp[i][j] = (dp[i - 1][j] + dp[i - 1][max(0, j - a[i])]) % MOD;
	}
	
	for (int i = 1; i <= n; i ++ )
		(res += dp[i - 1][a[i] + 1]) %= MOD; 
	
	cout << res << '\n';
	
	return 0;
}

