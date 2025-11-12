#include<bits/stdc++.h>
#define int long long
using namespace std;
int read();
const int N = 110;
int a[N];
signed main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n = read(), m = read();
	for (int i = 1; i <= n * m; i++) {
		a[i] = read();
	}
	int k = a[1];
	sort(a + 1, a + n * m + 1);
	int h = 1, l = 1;
	for (int i = n * m; i >= 1; i--) {
		if (a[i] == k) {
			cout << l << " " << h;
			return 0;
		}
		if (l % 2 == 1) {
			h++;
			if (h > n) {
				h = n;
				l++;
			}
		} else if (l % 2 == 0) {
			h--;
			if (h < 1) {
				h = 1;
				l++;
			}
		}
	}
	return 0;
}
int read() {
	int Ca = 0;
	char Cr = ' ';
	int Cf = 1;
	while (Cr < '0' || Cr > '9') {
		Cr = getchar();
		if (Cr == '-') {
			Cf = -1;
		}
	}
	while (Cr >= '0' && Cr <= '9') {
		Ca = Ca * 10 + Cr - '0';
		Cr = getchar();
	}
	return Ca * Cf;
}