#include <bits/stdc++.h>
using namespace std;
#define N 110
int n, m;
int a[N];
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	cin >> a[1];
	int peo = 0;
	for (int i = 2; i <= n * m; ++ i)  {
		cin >> a[i];
		if (a[i] > a[1]) {
			peo ++;
		}
	}
	if (peo == 0) {
		cout << 1 << " " << 1;
		return 0;
	}
	if (peo == n * m - 1) {
		if (m % 2 == 0) {
			cout << m << " " << 1;
		} else {
			cout << n << " " << m;
		}
		return 0;
	}
	int i = 1, j;
	peo ++;
//	cout << peo << '\n';
	while (peo - n > 0) {
		i ++;
		peo -= n;
	}
//	cout << peo << '\n';
	if (i % 2 == 0) {
		j = n - peo + 1;
	} else {
		j = peo;
	}
	cout << i << " " << j << '\n';
	return 0;
}
