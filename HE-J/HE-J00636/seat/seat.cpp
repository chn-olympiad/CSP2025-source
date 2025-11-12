#include <bits/stdc++.h>
using namespace std;
long long a[100000000];
int main() {
	freopen("seat.in","r", stdin);
	freopen("seat.out","w", stdout);
	long long n;
	long long m;
	cin >> n >> m;
	int sum = n * m;
	for (int i = 0; i < sum; i++) {
		cin >> a[i];
	}
	int q = a[0];
	sort (a, a + sum);
	int w = 1;
	for (int i = sum - 1; i >= 0; i--) {
		if (a[i] == q) {
			break;
		}
		w++;
	}
	int c = 0;
	int r = 0;
	c = w / n + 1;
	if (w % n == 0) {
		c -= 1;
	}
	if (c % 2 != 0) {
		r = w - (c - 1) * n;
		cout << c << " " << r;
		return 0;
	}else {
		r = c * n - w + 1;
		cout << c << " " << r;
		return 0;
	}
	return 0;
}
