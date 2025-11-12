#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5010;
const int mod = 998244353;
int n, a[N], c[N];
ll ans, comb[N][N];

void dfs(int i) {
	if (i == n + 1) {
		int mx = 0, sum = 0, d = 0;
		for (int j = 1; j <= n; j++) 
			if (c[j]) {
				d++;
				mx = max(mx, a[j]);
				sum += a[j];
			}
		if (sum > 2 * mx && d >= 3) ans = (ans + 1) % mod;
		return;	
	}
	c[i] = 0;
	dfs(i + 1);
	c[i] = 1;
	dfs(i + 1);
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}
	if (n <= 20) {
		dfs(1);	
		printf("%lld", ans % mod);
		return 0;
	}
		for (int i = 0; i <= n; i++) {
			comb[i][0] = comb[i][i] = 1;
			for (int j = 1; j < i; j++)
				comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % mod;
		}
//	printf("%lld %lld\n", comb[5][4], comb[5][5]);
		ll res = 0;
		for (int i = 3; i <= n; i++)	
			res = (res + comb[n][i]) % mod;
		printf("%lld", res);
		return 0;
} 	
