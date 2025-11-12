#include <bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using f64 = double;
using f80 = long double;

#define FILE "employ"
#define endl "\n"

const i64 MOD = 998244353;
const i32 N = 5e2 + 10;

i32 n, m, cnt;
string s;
i32 c[N];

i64 fac(i32 k) {
	i64 res = 1;
	for (i32 i=2; i<=k; ++i) res = res * i % MOD;
	return res;
}

void solve() {
	cin >> n >> m >> s;
	for (i32 i=1; i<=n; ++i) cin >> c[i];
	for (i32 i=0; i<n; ++i) cnt += (s[i] == '1');
	if (cnt == n) {
		cout << fac(n) << endl;
		return;
	}
	if (cnt < m) {
		cout << 0 << endl;
		return;
	}
}

int main() {
	freopen(FILE ".in", "r", stdin);
	freopen(FILE ".out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	solve();
	return 0;
}
