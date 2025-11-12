#include <bits/stdc++.h>
using namespace std;

const int kMaxN = 5002;
const int kM = 998244353;

int n, a[kMaxN], ans = 0;
map<int, bool> f;

void dfs(int l, int m, int s, int la) {
	if (l == n && s > 2 * m) {
		ans ++;
		return;
	}
	if (l >= 3 && s > 2 * m) {
		ans ++;
	}
	for (int i = 0; i < n; i ++) {
		if (!f[i] && i >= la) {
			f[i] = true;
			dfs(l + 1, m = max(a[i], m), s + a[i], i);
			f[i] = false;
		}
	}
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	cin >> n;
	for (int i = 0; i < n; i ++) {
		cin >> a[i];
		f[i] = false;
	}
	sort(a, a + n);
//	if (n < 3) cout << 0;
//	if (n == 3) {
//		int m = max(a[0], max(a[1], a[2]));
//		if (a[0] + a[1] + a[2] > m) cout << 1;
//	}
	dfs(0, 0, 0, 0);
	cout << (ans % kM);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
