#include <bits/stdc++.h>
using namespace std;

long long ans;
bool f[5010];
int n, x, a[5010];
void dfs(int s, int m, int d, int z) {
	if (d >= 3) {
		if (s > (m * 2)) {
			ans++;
			ans %= 998244353;
		}
		if (d >= n) return ;
	}
	for (int i = z + 1; i <= n; i++) {
		if (!f[i]) {
			f[i] = true;
			dfs(s + a[i], max(m, a[i]), d + 1, i);
			f[i] = false;
		}
	}
}
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	dfs(0, 0, 0, 0);
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
