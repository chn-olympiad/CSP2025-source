#include <map>
#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;
int n;
int ans;
int h[5005];
int a[5005];
void dfs(int, int, int);
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	dfs(1, 0, 0);
	cout << ans;
	return 0;
}
void dfs(int x, int total, int t) {
	if (t >= 3) {
		int maxn = -100;
		for (int i = 1; i <= x; i++) {
			maxn = max(maxn, h[i]);
		}
		if (total > maxn * 2) {
			ans++;
//			for (int i = 1; i <= x; i++) {
//			cout << h[i] << ' ';
//		}
//		cout << endl;
		}
	}
	if (x <= n) {
		h[x] = a[x];
		dfs(x + 1, total + a[x], t + 1);
		h[x] = 0;
		dfs(x + 1, total, t);
	}
}
// 100 + 100 + 40 + ? = 240+ pts 2=
