#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n;

long long a[N], b[N], c[N];

bool f[N];
int cnt[3];
long long x[N], y[N], z[N], xcnt, ycnt, zcnt;

bool cmp1(int x, int y) {
	return min(a[x] - b[x], a[x] - c[x]) < min(a[y] - b[y], a[y] - c[y]);
}

bool cmp2(int x, int y) {
	return min(b[x] - a[x], b[x] - c[x]) < min(b[y] - a[y], b[y] - c[y]);
}

bool cmp3(int x, int y) {
	return min(c[x] - b[x], c[x] - a[x]) < min(c[y] - b[y], c[y] - a[y]);
}

void solve() {
	cin >> n;
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> b[i] >> c[i];
		if (a[i] >= b[i] && a[i] >= c[i]) {
			x[++xcnt] = i;
			ans += a[i];
		} else if (b[i] >= a[i] && b[i] >= c[i]) {
			y[++ycnt] = i;
			ans += b[i];
		} else {
			z[++zcnt] = i;
			ans += c[i];
		}
	}
	if (xcnt > n / 2) {
		sort(x + 1, x + xcnt + 1, cmp1);
		for (int i = 1; i <= xcnt - n / 2; i++) {
			ans -= min(a[x[i]] - b[x[i]], a[x[i]] - c[x[i]]);
		} 
	} else if (ycnt > n / 2) {
		sort(y + 1, y + ycnt + 1, cmp2);
		for (int i = 1; i <= ycnt - n / 2; i++) {
			ans -= min(b[y[i]] - a[y[i]], b[y[i]] - c[y[i]]);
		} 
	} else if (zcnt > n / 2) {
		sort(z + 1, z + zcnt + 1, cmp3);
		for (int i = 1; i <= zcnt - n / 2; i++) {
			ans -= min(c[z[i]] - b[z[i]], c[z[i]] - a[z[i]]);
		} 
	}
	cout << ans << endl;
	xcnt = ycnt = zcnt = 0;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
