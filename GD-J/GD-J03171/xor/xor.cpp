#include <bits/stdc++.h>     
using namespace std;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	int a[500000] = {0}, p[500001] = {0};
	for (int i = 0; i < n; i++)
		cin >> a[i];
	p[1] = a[0];
	for (int i = 2; i <= n; i++) p[i] = p[i - 1] ^ a[i - 1];
	int b[500000] = {0};
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		bool t = false;
		for (int j = 0; j < i; j++) {
			if (b[j]) {
				t = true;
				break;
			}
		}
		if (t) continue;
		if (p[i] == k) {
			for (int j = 0; j < i; j++) b[j] = 1;
			ans++;
		}
		for (int j = 1; j < n - i + 1; j++) {
			if (b[j + i - 1]) continue;
			if (p[j + i] ^ p[j] == k) {
				ans++;
				for (int x = j; x < j + i; x++) b[x] = 1;
			}
		}
	}
	cout << ans;
	return 0;
}
