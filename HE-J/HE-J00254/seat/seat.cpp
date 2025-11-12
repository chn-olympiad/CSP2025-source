#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[105];

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 0; i < n * m; i++) {
		cin >> a[i];
	}
	int r = a[0];
	sort(a, a + n * m, cmp);
	int cur = 0;
	for (int i = 1; i <= m; i += 2) {
		for (int j = 1; j <= n; j++) {
			if (a[cur++] == r) {
				cout << i << ' ' << j << endl;
				return 0;
			}
		}
		for (int j = n; j >= 1; j--) {
			if (a[cur++] == r) {
				cout << i + 1 << ' ' << j << endl;
				return 0;
			}
		}
	}
	return 0;
}

