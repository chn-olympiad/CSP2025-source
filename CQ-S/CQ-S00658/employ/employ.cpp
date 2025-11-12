#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;
int n, m, p[510], dp[(1 << 18) + 10][20];
char s[510];

int main(){
	freopen ("employ.in", "r", stdin);
	freopen ("employ.out", "w", stdout);
	scanf ("%d%d", &n, &m);
	scanf ("%s", s + 1);
	for (int i = 1; i <= n; i++)
		scanf ("%d", &p[i]);
	if (n <= 18){
		dp[0][0] = 1;
		for (int i = 1; i < 1 << n; i++){
			int tot = 0;
			for (int j = 1; j <= n; j++)
				tot += ((i >> (j - 1)) & 1);
			for (int j = 1; j <= n; j++)
				if ((i >> (j - 1)) & 1)
					for (int k = 0; k <= n; k++) 
						if (k < p[j])
							dp[i][k + (s[tot] == '0')] += dp[i - (1 << (j - 1))][k], dp[i][k] %= mod;
						else
							dp[i][k + 1] += dp[i - (1 << (j - 1))][k], dp[i][k + 1] %= mod;
		}
		int ans = 0;
		for (int i = m; i <= n; i++)
			ans += dp[(1 << n) - 1][n - i], ans %= mod;
		printf ("%d\n", ans);
	}
	return 0;
}
