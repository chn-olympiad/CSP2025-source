#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 2, K = 1e6 + 2;
int n, k, a[N], s[N], pos[K], res;
signed main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> k, memset(pos, -1, sizeof pos);
	pos[0] = 0;
	for (int i = 1; i <= n; i++) cin >> a[i], s[i] = s[i - 1] ^ a[i];
	for (int i = 1, lst = 0; i <= n; i++) {
		if (pos[s[i] ^ k] >= lst) res++, lst = i;
		pos[s[i]] = i;
	}
	cout << res << '\n';
	return 0;
}
/*
4 1
2 1 0 3
*/
