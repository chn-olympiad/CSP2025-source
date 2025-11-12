#include <bits/stdc++.h>
using namespace std;

const int N = 5010, mod = 998244353;
int n, a[N], ans;
long long fac[N];

void dfs(int x, int res, int mx, int cnt) {
	if (x > n) {
		if (cnt <= 2 || res <= 2 * mx) return;
		ans = (ans + 1) % mod;
		return;
	}
	dfs(x + 1, res, mx, cnt);
	dfs(x + 1, res + a[x], a[x], cnt + 1);
}

void solve1() {
	dfs(1, 0, 0, 0);
	printf("%d", ans);
}

long long qmi(long long x, long long k) {
	long long res = 1;
	while (k) {
		if (k & 1) res = res * x % mod;
		k >>= 1;
		x = x * x % mod;
	}
	return res;
}

long long inv(int x) {
	return qmi(x, mod - 2) % mod;
}

long long C(int n, int m) {
	return fac[n] * inv(fac[m]) % mod * inv(fac[n - m]) % mod;
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	if (n <= 20) solve1();
	else if (a[n] <= 1) {
		if (a[n] == 0) { printf("0"); return 0; }
		else {
			fac[0] = 1;
			for (int i = 1; i <= n; i++)
				fac[i] = 1ll * fac[i-1] * 1ll * i % mod;
			int pos = 0;
			for (int i = 1; i <= n; i++)
				if (a[i] == 1) {
					pos = i;
					break;
				}
			long long res = 0;
			for (int i = 3; i <= n - pos + 1; i++)
				for (int j = 3; j <= i; j++)
					res = (res + 1ll * C(n - pos + 1, j) * C(pos - 1, i - j) % mod) % mod;
			printf("%lld", res);
		}
	}
	return 0;
}
