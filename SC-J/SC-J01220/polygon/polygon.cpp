#include <bits/stdc++.h>
#define E(i, l, r) for(int i = l;i <= r;++ i)
#define F(i, l, r) for(int i = r;i >= l;-- i)
using ll = long long;
using namespace std;
using P = pair<int, int>;
const ll MOD = 998244353;
int tt; 
namespace wangcy {
	const int N = 1e5 + 10;
	int n;
	ll ans, f[N], pw[N], V, a[N];
	inline void Main() {
		cin >> n, pw[0] = 1;
		E(i, 1, n) cin >> a[i], V = max(V, a[i]), pw[i] = pw[i - 1]*2%MOD;
		++ V;
		stable_sort(a + 1, a + n + 1);
		E(i, 1, n) {
			F(j, a[i] + 1, V) f[j] = f[j] + f[j - a[i]], f[j] %= MOD;
			F(j, 1, a[i]) f[j] = f[j] + pw[i - 1], f[j] %= MOD;
			if(i >= 2 && i < n) ans += f[a[i + 1] + 1], ans %= MOD;
		}
		return cout << ans << "\n", void();
	}
}
int main() {
	freopen("polygon.in", "r", stdin), freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	tt = 1;
	while(tt --) wangcy::Main();
	return 0;
}
// Ex : 100pts