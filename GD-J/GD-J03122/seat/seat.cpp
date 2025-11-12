#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int n, m;
int a[101], ans[101];

int cmp(const int x, const int y) {
	return x > y;
}

int fin(const int x) {
	for (int i = 1; i <= n * m; i ++) {
		if (a[i] == x) {
			return i;
		}
	}
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i ++) {
		cin >> a[i];
	}
	int xr = a[1];
	sort(a + 1, a + n * m + 1, cmp);
	int ans = fin(xr);
	cout << int(ceil(ans / (m * 1.0))) << " ";
	if (int(int(ceil(ans / (m * 1.0))) % 2) != 0) {
		cout << (ans + int(ceil(ans / (m * 1.0))) - 1) % (m + 1) << endl;
	}
	else {
		cout << (m + 1) - (ans + int(ceil(ans / (m * 1.0))) - 1) % (m + 1) << endl;
	}
	return 0;
}
