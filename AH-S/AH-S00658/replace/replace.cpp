#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const LL N = 2e5 + 10;

LL n, q;
string a[N], b[N], x, y;

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (LL i = 1; i <= n; i++) cin >> a[i] >> b[i];
	while (q--) {
		cin >> x >> y;
		LL ans = 0;
		for (LL i = 1; i <= n; i++) {
			LL m = x.find(a[i]);
			LL n = y.find(b[i]);
			if (m != string::npos && m == n) {
				string t = x;
				t.replace(m, a[i].size(), b[i]);
				if (t == y) ans++;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}