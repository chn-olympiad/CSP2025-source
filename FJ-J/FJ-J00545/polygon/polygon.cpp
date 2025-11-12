#include <bits/stdc++.h>

using namespace std;

int n, s = 0, maxv = 0;
int a[5010];

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
		s += a[i];
		maxv = max(a[i], maxv);
	}
	
	if (s > 2 * maxv) {
		cout << 1;
	} else {
		cout << 0;
	}
	
	return 0;
}
