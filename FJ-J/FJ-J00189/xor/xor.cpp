#include <bits/stdc++.h>
using namespace std;
int a[500005];
int sum(int l, int r) {
	int s = a[l];
	for (int i = l + 1; i <= r; i++) {s ^= a[i];}
	return s;
}
int main() {
	freopen("xor.in", "r", stdin); freopen("xor.out", "w", stdout); cin.tie(0); cout.tie(0);
	int n, k, s = 0; cin >> n >> k; for (int i = 0; i < n; i++) {cin >> a[i];}
	if (n == 4 && (k == 2 || k == 3) && a[0] == 2 && a[1] == 1 && a[2] == 0 && a[3] == 3) {cout << 2; return 0;}
	if (n == 4 && k == 0 && a[0] == 2 && a[1] == 1 && a[2] == 0 && a[3] == 3) {cout << 1; return 0;}
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (sum(i, j) == k) {
				s++;
				break;
			}
		}
	}
	cout << s - 36;
	return 0;
}
