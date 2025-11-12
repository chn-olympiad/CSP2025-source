#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t, n;
	cin >> t;
	while(t--) {
		cin >> n;
		int s = 0, x = 0, y = 0, z = 0;
		for (int i = 0; i < n; i++) {
			int a[3];
			int b[101];
			for (int j = 0; j < 3; j++) {
				cin >> a[i];
				b[i] = a[i];
			}
			sort(a, a + 3);
			s = s + a[2];
			for (int j = 0; j < 3; j++) {
				if (a[2] == b[j] && j == 0) {
					x++;
				}else if (a[2] == b[j] && j == 1) {
					y++;
				}else {
					z++;
				}
			}
			if (x > (n / 2)) {
				if (y > (n / 2)) {
					s = s - a[2] + b[2];
				}else {
					s = s - a[2] + b[1];
				}
				x -= 1;
			}
			if (y > (n / 2)) {
				if (z > (n / 2)) {
			    	s = s - a[2] + b[0];
				}else {
					s = s - a[2] + b[2];
				}
				y -= 1;
			}
			if (z > (n / 2)) {
				if (x > (n / 2)) {
					s = s - a[2] + b[0];
				}else {
					s = s - a[2] + b[1];
				}
				z -= 1;
			}
		}
		cout << s << endl;
	}
	return 0;
}
