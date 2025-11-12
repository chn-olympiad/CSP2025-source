#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);

	int n, m, a[110], r, h = 0;
	cin >> n >> m >> r;
	for (int i = 1; i <= n * m - 1; i++) {
		cin >> a[i];
		if (a[i - 1] >= r && a[i] <= r) {
			h = i;
		}
	}

	sort(a, a + n * m - 1, greater<int>());

	for (int i = 1; i <= n * m - 1; i++) {
		if (a[i - 1] >= r && a[i] <= r) {
			h = i;
		}
	}

	int tmp = ceil(1.0 * h / n), tmp2 = h % n;
//	cout << tmp2 << endl;
	if (tmp == 0) tmp = m;
	if (tmp2 == 0) tmp2 = n;
//	cout << n << ' ' << m << ' ' << tmp << ' ' << h << endl;
	if (tmp % 2 == 0) {
		cout << tmp << ' ' << n - tmp2 + 1;
	} else {
		cout << tmp << ' ' << tmp2;
	}

//	cout << h;

	fclose(stdin);
	fclose(stdout);

	return 0;
}
