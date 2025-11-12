#include <bits/stdc++.h>
using namespace std;
struct st {
	int a, b, c;
}x[100010];
int cmp(st a, st b) {
	return a.a > b.a;
}
int main() {
	freopen("cluc.in", "r", stdin);
	freopen("cluc.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t, n, ans;
	cin >> t;
	while (t--) {
		cin >> n; ans = 0;
		for (int i = 1; i <= n; i++) cin >> x[i].a >> x[i].b >> x[i].c;
		sort (x + 1, x + n + 1, cmp);
		for (int i = 1; i <= n / 2; i++) ans += x[i].a;
		cout << ans << "\n";
	}
	return 0;
}
