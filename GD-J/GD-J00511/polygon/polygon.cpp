#include <bits/stdc++.h>

using namespace std;

#define mod 998244353

inline long long A(int n, int m) {
	long long res = 1;
	for (int i = n; i >= n - m + 1; -- i) {
		res = res * n % mod;
	}
	return res;
}
inline long long C(int n, int m) {
	return A(n, m) % mod / A(n, n) % mod;
}

int n;
int a[5007];
bool fg = true;
long long ans;

inline void dfs(int p, int cnt, int ed, long long sum, long long maxn) {
	if (cnt == ed) {
		if (sum > (maxn << 1ll)) {
			++ ans;
			ans %= mod;
		}
		return ;
	}
	if (p > n) {
		return ;
	}
	dfs(p + 1, cnt, ed, sum, maxn);
	dfs(p + 1, cnt + 1, ed, sum + a[p], max(maxn, (long long)a[p]));
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%d", & n);
	for (int i = 1; i <= n; ++ i) {
		scanf("%d", & a[i]);
		if (a[i] > 1) {
			fg = false;
		}
	}
	if (n < 3) {
		puts("0");
		return 0;
	}
	if (fg) {
		long long ans = 0;
		for (int i = 3; i <= n; ++ i) {
			ans = (ans + C(i, n) % mod) % mod;
		}
		printf("%lld\n", ans);
		return 0;
	}
	for (int i = 3; i <= n; ++ i) {
		dfs(1, 0, i, 0ll, 0ll);
	}
	printf("%lld\n", ans);
	return 0;
}
