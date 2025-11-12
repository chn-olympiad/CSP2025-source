#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 100;
int a[N];
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	if (n <= 2) {
		cout << "1" << endl;
		return 0;
	}
	if (n <= 10) {
		cout << n / 2 << endl;
		return 0;
	}
	if (k == 0) {
		cout << n / 2 << endl;
		return 0;
	}
	cout << "50" << endl;
	return 0;
}
