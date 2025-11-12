#include <bits/stdc++.h>
#define int long long

template<typename T> void ckadd(T &x, T y, T p) { x = (x + y) % p; }
template<typename T> void ckmul(T &x, T y, T p) { x = (x * y) % p; }
template<typename T> void ckmax(T &x, T y) { x = x > y ? x : y; }
template<typename T> void ckmin(T &x, T y) { x = x < y ? x : y; }

const int N = 5e3 + 7;
const int Mod = 998244353;

int f[N], a[N];
int n, ans;

int ksm(int x, int k) { int res = 1; for (; k; k >>= 1, ckmul(x, x, Mod)) if (k & 1) ckmul(res, x, Mod); return res; }

namespace sub {
	int check() { for (int i = 1; i <= n; i ++) if (a[i] != 1) return 0; return 1; }
	void dfs(int dep, int sum, int x) {
		if (dep == x) return ans += sum > a[x], void();
		dfs(dep + 1, sum + a[dep], x);
		dfs(dep + 1, sum, x);
	}
	void task1() {
		std::sort(a + 1, a + n + 1);
		for (int i = 3; i <= n; i ++) dfs(1, 0, i);
		printf("%lld", ans);
	}
	void task2() {
		ans = ksm(2ll, n) - (n * (n - 1) / 2) - n + Mod - 1;
		printf("%lld", ans % Mod); 
	}
}

signed main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	scanf("%lld", &n); for (int i = 1; i <= n; i ++) scanf("%lld", &a[i]);
	if (n <= 20) return sub::task1(), 0;
	if (sub::check()) return sub::task2(), 0;
	std::sort(a + 1, a + n + 1);
	f[0] = 1; a[0] = 114514;
	for (int i = 1; i <= n; i ++) {
		for (int j = 0; j < i; j ++) if (2 * a[j] >= a[i]) ckadd(f[i], f[j], Mod);
	}
	printf("%lld", f[n] - 1);
	
	return 0;
}

