#include<bits/stdc++.h>
using namespace std;


int a[1100];
bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n * m; ++i) cin >> a[i];
	int s = a[1];
	sort(a + 1, a + n*m + 1, cmp);
	for (int i = 1; i <= n * m; ++i) {
		if (a[i] == s) {
			int c = i / n, r = 0;
			if (i % n == 0) {
				if (c % 2 == 1) r = n;
				else r = 1;
			} else {
				if ((c + 1) % 2 == 1) r = i - c * n;
				else r = n - (i - c*n) + 1;
				c += 1;
			}
			cout << c << " " << r;
			break;
		}
	}


	return 0;
}