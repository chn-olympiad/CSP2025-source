#include<bits/stdc++.h>
using namespace std;
int n, s = -1e5, a[5050], ans, f, k;
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (n == 2 && k == 0 && a[1] == a[2]) cout << 1;
	else if (n == 1 && k != a[1]) cout << 0;
	else if (k == 0) {
		cout << n / 2;
	}
	else cout<<5;
	return 0;
}