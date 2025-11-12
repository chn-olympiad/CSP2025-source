#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, a[1000010];
bool flag = 1;
signed main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	if (n == 3) {
		if (a[1] + a[2] > a[3] && a[1] + a[3] > a[2] && a[2] + a[3] > a[1])
			cout << 1;
		else
			cout << 0;
	}
	else 
		cout << 0;
	return 0;
}