// AH-J01016

#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const LL N = 5e3 + 10;

const LL MOD = 998244353;

LL n, a[N], f[N][N], s[N][N];
LL cnt = 0;

void dfs(LL cur, LL pre, LL sum) {
	if (cur > 3) {
		if (sum > 2 * a[pre]) cnt = (cnt + 1) % MOD;
	}
	for (LL i = pre + 1; i <= n; i++) {
		dfs(cur + 1, i, sum + a[i]);
	}
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%lld", &n);
	for (LL i = 1; i <= n; i++) {
		scanf("%lld", a + i);
	}
	sort(a + 1, a + n + 1);
	if (n == 3) {
		if (a[1] + a[2] > a[3]) printf("1\n");
		else printf("0\n");
		return 0;
	}
	if (a[n] == 1) {
		printf("%lld\n", (n * (n - 1) * (n - 2) / 6) % MOD);
		return 0;
	}
	if (n <= 10) {
		dfs(1, 0, 0);
		printf("%lld\n", cnt % MOD);
		return 0;
	}
	/*
	 * Use DP.
	 * f(i,j): choose j from 1~i.
	 * s(i,j): max sum.
	 * f(0,0)=1
	 * 1<=k<i:
	 *     (if) s(k,j-1)>a[i]
	 *     f(i,j)+=f(k,j-1)
	 *     s(i,j)=max(s(i,j),s(k,j-1))
	 */
	f[0][0] = 1;
	for (LL i = 1; i <= n; i++) {
		for (LL j = 1; j <= i; j++) {
			for (LL k = 0; k < i; k++) {
				if (s[k][j - 1] > a[i]) {
					f[i][j] += f[k][j - 1];
					s[i][j] = max(s[i][j], s[k][j - 1]);
				}
			}
		}
	}
	LL tot = 0;
	for (LL i = 1; i <= n; i++) {
		for (LL j = 3; j <= i; j++) {
			tot += f[i][j];
		}
	}
	printf("%lld\n", tot);
	return 0;
}
