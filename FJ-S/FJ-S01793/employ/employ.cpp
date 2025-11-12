#include <bits/stdc++.h>
//#define int long long
using namespace std;

const int N = 1e5 + 2;

int n, m, a[N], b[N], c[N], ans;
char x;

signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++) cin >> x, a[i] = x - '0';
	for (int i = 1;i <= n;i++) b[i] = i;
	for (int i = 1;i <= n;i++) cin >> c[i];
	while (next_permutation(b + 1, b + 1 + n)) {
		int x = 0, ok = 0;
		for (int i = 1;i <= n;i++) {
			if (x <= c[i]) ok++;
			else x++;
		ans += ok >= m;
	}
	cout << ans << endl;
	return 0;
}


