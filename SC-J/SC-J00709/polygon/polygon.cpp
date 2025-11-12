#include <iostream>
using namespace std;
const int MAXN = 5010, Mod = 998224353;
int n, a[MAXN], ans, nxt[MAXN];
bool vis[MAXN];
inline void init() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = n - 1; i >= 1; i--) {
		nxt[i] = nxt[i + 1] + a[i + 1];
	}
	return;
}
void dfs(int x, int k, int cnt, int sigma) {
	if (x >= 3 && 2 * k < sigma) {
		ans++;
	}
	if (x >= 3 && 2 * k >= sigma + nxt[x]) {
		return;
	}
	for (int i = x + 1; i <= n; i++) {
		vis[i] = true;
		dfs(i, max(k, a[i]), cnt + 1, sigma + a[i]);
		vis[i] = false;
	}
}
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	init();
	dfs(0, 0, 0, 0);
	cout << ans << '\n';
	return 0;
}