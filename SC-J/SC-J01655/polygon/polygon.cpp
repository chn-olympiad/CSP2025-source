#include <bits/stdc++.h>
using namespace std;
int a[110];
int main() {
    freopen("polygon.in" , "r" , stdin);
    freopen("polygon.out" , "w" , stdout);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int cnt = 0;
	sort(a , a + n);
	for (int i = 2; i < n; i++) {
		int c = a[i];
		for (int j = 1; j <= 2; j++) {
			c += a[i - j];
		}
		if (c > a[i] * 2) {
			cnt += n - 2;
		}
	}
	cout << cnt;
	return 0;
}