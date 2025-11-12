#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 9;
bool cmp(int x, int y) {
	return x > y;
};
signed main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, a[N], cnt, g;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	cnt = a[1];
	sort(a + 1, a + 1 + n * m, cmp);
	for (int i = 1; i <= n * m; i++) {
		if (a[i] == cnt) {
			g = i;
		}
	}
	if (g % n == 0) {
		if ((g / n) % 2 == 0) {
			cout << g / n << " " << 1;
		} else {
			cout << g / n << " " << n;
		}
	} else {
		if ((g / n + 1) % 2 == 0) {
			cout << g / n + 1 << " " << n + 1 - (g % n);
		} else {
			cout << g / n + 1 << " " << g % n;
		}
	}
	return 0;
}
