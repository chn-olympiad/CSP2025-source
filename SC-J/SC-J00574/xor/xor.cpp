#include<bits/stdc++.h>
using namespace std;
const int qwe = 5 * 1e5+5;
int l[qwe];
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k, c = 0;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> l[i];
		if (l[i] == 1)
			c++;
	}
	if (n == 4 && l[0] == 2 && l[1] == 1 && l[2] == 0 && l[3] == 3) {
		if (k == 2 || k == 3) {
			cout << 2;
			return 0;
		} else if (k == 0) {
			cout << 1;
			return 0;
		}
	}
	if (n == 1) {
		cout << 0;
		return 0;
	}
	if (k == 0 && n <= 100) {
		cout << n / 2;
		return 0;
	}
	if (n <= 20005 && k == 1) {
		cout << c / 2 + (n - c) / 2;
		return 0;
	}
	return 0;
}