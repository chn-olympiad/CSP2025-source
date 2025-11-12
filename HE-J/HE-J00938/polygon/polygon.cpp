#include<bits/stdc++.h>
#define up(i,l,r) for(ll i=l,E##i=r;i<=E##i;++i)
#define dn(i,l,r) for(ll i=l,E##i=r;i>=E##i;--i)
using namespace std;
typedef long long ll;
constexpr ll N = 5 + 5000, M = 998244353;
ll n, a[N], f[N];
void makef() {
	f[1] = 1;
	up (i, 2, n) f[i] = (f[i - 1] * 2 + 1) % M;
}
namespace solve1 {
	void main() {
		cout << f[n] << endl;
	}
}
namespace solve2 {
	ll ans = 0;
	void dfs(ll p, ll mx, ll sum, ll cnt) {
		if (cnt >= 3 && sum > mx * 2) {
			(ans += f[n - p + 1] + 1) %= M;
			return;
		}
		if (p > n) return;
		dfs(p + 1, mx, sum, cnt);
		dfs(p + 1, max(mx, a[p]), sum + a[p], cnt + 1);
	}
	void main() {
		sort(a + 1, a + n + 1, greater<ll>());
		dfs(1, 0, 0, 0);
		cout << ans << endl;
	}
}
namespace solve3 {
	// 想不出转移方程 QwQ
}
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	up (i, 1, n) cin >> a[i];
	ll mx = *max_element(a + 1, a + n + 1);
	makef();
	if (mx <= 1) solve1::main();
	else solve2::main();
	return 0;
}
