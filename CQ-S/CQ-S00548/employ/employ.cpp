#include <bits/stdc++.h>
using namespace std;
namespace WorldMachine {
typedef long long ll;
const int N = 505, p = 998244353;
int n, m, c[N], b[N]; char a[N];
void main() {
	freopen("employ.in", "r", stdin), freopen("employ.out", "w", stdout);
	scanf("%d%d%s", &n, &m, a + 1);
	for (int i = 1; i <= n; i++) scanf("%d", &c[i]);
	if (m == n) {
		bool flg = 1; for (int i = 1; i <= n; i++) if (a[i] == '0' || !c[i]) { flg = 0; break; }
		if (!flg) { return cout << 0, void(); } int fac = 1;
		for (int i = 1; i <= n; i++) { fac = (ll)fac * i % p; } cout << fac; return;
	}
	for (int i = 1; i <= n; i++) { b[i] = i; } int ans = 0;
	do {
		int cnt = 0, ret = 0;
		for (int i = 1; i <= n; i++) {
			if (cnt >= c[b[i]] || a[i] == '0') cnt++;
			else ret++;
		} if (ret >= m) ans++;
	} while (next_permutation(b + 1, b + 1 + n));
	cout << ans;
}
}
int main() { return WorldMachine::main(), 0; }
