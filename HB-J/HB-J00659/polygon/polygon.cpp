#include <bits/stdc++.h>
using namespace std;
typedef long long int LL;
const int MAXN = 5e3 + 5;
const LL mod = 998244353;
int n;
LL a[MAXN];
bool bk[MAXN];
bool ONE = true;
LL fpow(LL x, int y) {
	LL res = 1;
	while (y) {
		if (y & 1)	res = res * x % mod;
		x = x * x % mod;
		y >>= 1;
	}
	return res;
}
LL inv(LL x) {
	return fpow(x, mod - 2);
}
namespace tri { //12
	void solve() {
		printf("%d", (((a[1] + a[2] > a[3]) && (a[2] + a[3] > a[1]) && (a[3] + a[1] > a[2])) ? 1 : 0));
	}
}
namespace one { //24
	LL ans = 0;
	void solve() {
		for (LL i = 3; i <= n; ++i) {
			LL a = 1, b = 1;
			for (LL j = 0; j < i; ++j) {
				a = a * (n - j) % mod;
				b = b * (1 + j) % mod;
			}
			ans = (ans + a * inv(b) % mod) % mod;
		}
		printf("%lld", ans);
	}
}
namespace bf { //24
	LL ans = 0;
	void dfs(int u) {
		if (u == n + 1) {
			LL mx = -1, sum = 0;
			int tot = 0;
			for (int i = 1; i <= n; ++i)
				if (bk[i]) {
					++tot;
					sum += a[i];
					mx = max(mx, a[i]);
				}
			if (tot >= 3 && (mx << 1) < sum)
				ans = (ans + 1) % mod;
			return;
		}
		bk[u] = false;
		dfs(u + 1);
		bk[u] = true;
		dfs(u + 1);
	}
	void solve() {
		dfs(1);
		printf("%lld", ans);
	}
}
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%lld", &a[i]);
		if (a[i] > 1)	ONE = false;
	}
	if (n == 3)	tri::solve();
	else if (ONE)	one::solve();
	else if (n <= 20)	bf::solve();
	return 0;
}