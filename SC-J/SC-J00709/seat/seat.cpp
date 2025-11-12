#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 1010;
int n, m, a[MAXN], ask;
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	} 
	ask = a[1];
	sort(a + 1, a + 1 + n * m, greater<int>());
	int l = 1, r = n * m + 1, mid;
	while (r - l > 1) {
		mid = (l + r) / 2;
		if (a[mid] >= ask) {
			l = mid;
		} else {
			r = mid;
		}
	}
	int ans_c = l / n + ((l % n == 0) ? 0 : 1), ans_r;
	if (ans_c % 2 == 0) {
		ans_r = n + 1 - l % n;
		if (ans_r == n + 1) ans_r = n;
	} else {
		ans_r = l % n;
		if (ans_r == 0) ans_r = n;
	}
	cout << ans_c << ' ' << ans_r << '\n';
	return 0;
}