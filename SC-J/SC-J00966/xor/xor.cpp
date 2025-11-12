#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, k, a[1000010], ans;
signed main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i ++)
		cin >> a[i];
	for (int i = 1; i <= n; i ++)
		if (a[i] == 1)
			ans ++;
	cout << ans;
	return 0;
}