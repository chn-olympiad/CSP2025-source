#include <bits/stdc++.h>
using namespace std;
#define N 500010
int n, k;
int a[N];
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; ++ i) {
		cin >> a[i];
	}
	if (n == 0) {
		cout << 1 ;
		return 0;
	}
	int ans = 0;
	int j = 0;
	for (int i = 1; i <= n; ++ i) {
		j ^= a[i];
		if (j == k) {
			ans ++;
			j = 0;
			continue;
		}
	}
	cout << ans << '\n';
	return 0;
}
