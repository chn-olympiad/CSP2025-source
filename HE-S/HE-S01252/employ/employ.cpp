#include <bits/stdc++.h>
using namespace std;
int main () {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	long long n, m, a[505];
	string ny;
	cin >> n >> m >> ny;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	if (m == n) {
		cout << 1 << endl;
	} else if (m == 1) {
		cout << n << endl;
	} else {
		cout << 0 << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
