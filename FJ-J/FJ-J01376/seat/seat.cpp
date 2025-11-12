#include <bits/stdc++.h>
using namespace std;
int n,m, a[105];
int main () {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	cin >> a[1];
	int cnt = 1;
	for (int i = 2; i <= n*m; i++) {
		cin >> a[i];
		if (a[i] > a[1]) cnt++;
	}
	int c=1, r = 1;
	if (m == 1) {
		cout << "1 " << cnt;
	}
	for (int i =1; i < cnt; i++) {
		if (c % 2 == 1) {
			if (r<n) {
				r++;
			} else {
				c++;
			}
		}
		else {
			if (r>1) {
				r--;
			} else {
				c++;
			}
		}
	}
	cout << c << " " << r;
	return 0;
}
