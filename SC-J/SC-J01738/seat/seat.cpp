#include <bits/stdc++.h>
using namespace std;
const int maxn = 110;
int a[maxn];
bool cmp(int x, int y) {
	return x > y;
}
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) cin >> a[i];
	int d = a[1], k = 0;
	sort(a + 1, a + n*m + 1, cmp);
	for (int i = 1; i <= n * m; i++) {
		if (a[i] == d) {
			k = i;
			break;
		}
	}
	if (k % n == 0) {
		cout << k / n << " ";
		if ((k / n) % 2 == 0) cout << 1;
		else cout << n;
	} else {
		cout << k / n + 1 << " ";
		if ((k / n + 1) % 2 == 0) {
			cout << n - (k % n) + 1;
		} else {
			cout << (k % n);
		}
	}
	return 0;
}