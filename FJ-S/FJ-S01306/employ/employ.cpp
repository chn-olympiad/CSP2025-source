#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int p = 998244353;

int n, m, a[510];
int dp[1 << 18][20];
char s[510];

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
//	freopen("employ2.in", "r", stdin);
	scanf("%d%d%s", &n, &m, s + 1);
	for (int i = 1 ; i <= n ; i++)
		scanf("%d", &a[i]);
	if (n <= 18) {
		dp[0][0] = 1;
		for (int S = 0 ; S < (1 << n) ; S++) {
			int i = 0;
			for (int j = 0 ; j < n ; j++)
				if (S & (1 << j)) ++i;
			for (int j = 0 ; j <= i ; j++)
				for (int k = 0 ; k < n ; k++)
					if (!(S & (1 << k))) {
						bool none = (s[i + 1] == '0' || a[k + 1] <= j);
						dp[S | (1 << k)][j + none] = (dp[S | (1 << k)][j + none] + dp[S][j]) % p;
					}
		}
//		for (int i = 0 ; i <= n ; i++) {
//			for (int j = 0 ; j < (1 << n) ; j++)
//				cout << dp[i][j] << " ";
//			puts("");}
		int ans = 0;
		for (int i = 0 ; i <= n - m ; i++)
			ans = (ans + dp[(1 << n) - 1][i]) % p;
		printf("%d\n", ans);
	} else if (m == n) {
		ll ans = 1;
		for (int i = 1 ; i <= n ; i++)
			ans &= (s[i] == '1') && (a[i] > 0);
		for (int i = 1 ; i <= n ; i++)
			ans = ans * i % p;
		printf("%lld\n", ans);
	} else {
		ll ans = 1;
		for (int i = 1 ; i <= n ; i++)
			ans &= (s[i] == '1');
		if (ans) {
			int flag = 0;
			for (int i = 1 ; i <= n ; i++)
				flag += (a[i] > 0);
			ans = (flag >= m);
			for (int i = 1 ; i <= n ; i++)
				ans = ans * i % p;
			printf("%lld\n", ans);
		} else puts("0");
	}
	return 0;
}
