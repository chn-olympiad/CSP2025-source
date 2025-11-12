#include <bits/stdc++.h>
#define int long long
#define endl "\n"

using std::cin;
using std::cout;

int a[1001];

bool cmp(int a, int b) {
	return a > b;
}

signed main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	int r = a[1];
	int p = 1;
	std::sort(a + 1, a + n * m + 1, cmp);
	for (int i = 1; i <= n * m; i++) {
		if (a[i] == r) {
			p = i;
			break;
		}
	}
	for (int i = 1; i <= m; i++) {
		if (i % 2 == 0) {
			for (int j = n; j >= 1; j--) {
				p--;
				if (p == 0) {
					cout << i << " " << j;
					return 0;
				}
			}
			continue;
		}
		else {
			for (int j = 1; j <= n; j++) {
				p--;
				if (p == 0) {
					cout << i << " " << j;
					return 0;
				}
				
			}
				
		}
	}
	return 0;
}