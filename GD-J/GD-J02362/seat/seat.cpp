#include <bits/stdc++.h>
using namespace std;
signed main() {
	freopen("seat.in", "r", stdin); 
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	vector <int> a(n * m + 1);
	for (int i = 1; i <= n * m; i++) cin >> a[i];
	int A = a[1];
	sort(a.begin() + 1, a.end(), greater <int>());
	int x = 1, y = 0, idx = 1;
	bool f = 0;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (f) y--;
			else y++;
			if (a[idx] == A)  {
				return cout << x << ' ' << y, 0;
				cout << "*";
			}
			//cout << x << ' ' << y << ' ' << a[idx] << endl;
			idx++;
		}
		x++;
		if (f) y--;
		else y++;
		f = !f;
	}
	cout << x << ' ' << y;
	return 0;
}
/*
2 2
98 99 100 97
*/
