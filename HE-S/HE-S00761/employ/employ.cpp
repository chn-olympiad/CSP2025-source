#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
const int mod = 998244353;
char c[N];
int a[N], b[N];
int main () {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> c[i], a[i] = i;
	for (int i = 1; i <= n; i++) cin >> b[i];
	int ans = 0;
	do {
		int now = 0;
		for (int i = 1; i <= n; i++) {
			if (i - 1 - now >= b[a[i]]) continue;
			if (c[i] == '1') now++;
		}
		if (now >= m) ans++;
		ans %= mod;
	}while (next_permutation(a + 1, a + n + 1));
	cout << ans << '\n';
}
