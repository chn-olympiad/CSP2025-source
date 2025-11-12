#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int n, m, a[N];
bool cmp(const int &x, const int &y) {
	return x > y;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	} 
	int s = a[1], now = 0, w = 0;
	sort(a + 1, a + n * m + 1, cmp);
	for (int i = 1; i <= n * m; i++) {
		if (a[i] == s) {
			w = i;
			break;
		}
	}
	for (int i = 1; i <= m; i++) {
		if (i % 2 == 1) {
			for (int j = 1; j <= n; j++) {
				now += 1;
				if (now == w) {
					cout << i << ' ' << j << '\n';
					return 0;
				}
			}
		}
		else {
			for (int j = n; j >= 1; j--) {
				now += 1;
				if (now == w) {
					cout << i << ' ' << j << '\n';
					return 0;
				}
			}
		}
	}
	return 0;
}
