#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10;
int n, k, a[N], m, ans;
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		int t = a[i];
		for (int j = i - 1; j > m; j--) {
			if(t == k) break;
			t ^= a[j];
		}
		if(t == k) m = i, ans ++;
	}
	cout << ans;

	return 0;
}
