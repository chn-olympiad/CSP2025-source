#include <bits/stdc++.h>
using namespace std;

const int MAXN = 600001;
int a[MAXN], n, k, ans, l, r, cnt;
bool b[MAXN], flag, d;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] > 1) flag = 1;
	}
	if (!k) {
		bool f;
		for (int i = 1; i <= n; i++) {
			if (a[i]) {
				f = 1;
				break;
			}
		}
		if (!f) cout << n / 2;
		else {
			for (int i = 1; i <= n; i++) {
				if (!a[i]) ans++;
				if (a[i] == a[i + 1] && a[i] == 1 && !b[i] && !b[i + 1]) {
					ans++;
					b[i] = b[i + 1] = 1;
				}
			}
			cout << ans;
		}
		return 0;
	}
	if (!flag && k == 1) {
		for (int i = 1; i <= n; i++) {
			if (a[i] == k) ans++;
		}
		cout << ans;
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		if (a[i] == k) {
			ans++;
			b[i] = 1;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (!b[i]) continue;
		cnt = a[i];
		l = i;
		d = 0;
		for (int j = i + 1; j <= n; j++) {
			if (b[j]) break;
			if ((cnt ^ a[j]) == k) {
				r = j;
				d = 1;
				break;
			} else cnt = (cnt ^ a[j]);
		}
		if (d) {
			ans++;
			for (int j = l; j <= r; j++) b[j] = 1;
			d = 0;
		}
	}
	cout << ans;
	return 0;
}
