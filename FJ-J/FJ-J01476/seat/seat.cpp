#include <bits/stdc++.h>
using namespace std;
int cnt = 1;
signed main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, r, a;
	cin >> n >> m;
	for (int i = 0; i < n * m; i++) {
		cin >> a;
		if (i == 0) {
			r = a;
		} else {
			if (r < a) {
				cnt++;
			}
		}
	}
	int k = (cnt - 1) / n + 1, l = (cnt - 1) % n + 1;
	if (k % 2 == 0) {
		l = n - l + 1;
		//cout << "shcfgxn" << endl;
	}
	cout << k << ' ' << l;
}

