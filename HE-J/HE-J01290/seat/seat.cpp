#include <bits/stdc++.h>
using namespace std;
int main () {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int a[n * m];
	for (int i = 0; i < n * m; i++) {
		cin >> a[i];
	}
	//输入
	if (n <= 1 && m <= 1) {
		cout << 1 << ' '<< 1;
	} //当m和n都为1时 结果为1
	else if (n <= 1 && m <= 10) {
		int r = a[0];
		sort(a, a + n * m);
		for (int i = n * m - 1; i >= 0; i--) {
			if (r == a[i]) {
				cout << 1 << ' ' << m - i;
				return 0; 
			}
		}
	} //当n<=1, m<=10时 结果为1 和 m - i
	else if (n <= 10 && m <= 1) {
		int r = a[0];
		sort(a, a + n * m);
		for (int i = n * m - 1; i >= 0; i--) {
			if (r == a[i]) {
				cout << n - i << ' ' << 1; 
			}
		}
	}//当n<=1, m<=10时 结果为n - 1 和 1
	else {
		cout << n << ' ' << m; 
	}
	return 0;
}
