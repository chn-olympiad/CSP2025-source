#include <cstdio>
#include <algorithm>
using namespace std;

const int mod = 998244353;
int n, a[5001], ans;
bool t = true;
void dfs(int pl, int sm, int mx) {
	if (pl == n + 1) {
		if (sm > 2 * mx)
			ans = (ans + 1) % mod;
		return;
	}
	dfs(pl + 1, sm, mx);
	dfs(pl + 1, sm + a[pl], max(mx, a[pl]));
}
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		if (a[i] != 1)
			t = false;
	}
	dfs(1, 0, 0);
	printf("%d", ans);
	return 0;
}
