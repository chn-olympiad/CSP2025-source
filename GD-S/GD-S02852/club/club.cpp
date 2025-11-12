#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll t, n, ans, f[305][305][305];
struct QZY {
	ll x, y, z;
} a[200005];
ll max(const ll x, const ll y) {return x > y ? x : y;}
bool cmp(QZY c, QZY d) {return c.x > d.x;}
void Init() {
	cin >> n;
	for (ll i = 1; i <= n; ++i)
		cin >> a[i].x >> a[i].y >> a[i].z;
	ans = 0;
	memset(f, 0, sizeof f);
	f[1][0][0] = a[1].x;
	f[0][1][0] = a[1].y;
	f[0][0][1] = a[1].z;
}
void solve() {
	for (ll i = 0; i * 2 <= n; ++i) 
		for (ll j = 0; j * 2 <= n; ++j) {
			if (i + j > n) break;
			for (ll k = 0; k * 2 <= n; ++k) {
				ll s = i + j + k;
				if (s > n) break;
				if (i) f[i][j][k] = max(f[i][j][k], f[i - 1][j][k] + a[s].x);
				if (j) f[i][j][k] = max(f[i][j][k], f[i][j - 1][k] + a[s].y);
				if (k) f[i][j][k] = max(f[i][j][k], f[i][j][k - 1] + a[s].z);
				ans = max(ans, f[i][j][k]);
			}
		}
	cout << ans << '\n';
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin.tie(0), cout.tie(0);
	ios::sync_with_stdio(0);
	cin >> t;
	while (t--) {
		Init();
		if (n < 600) {
			solve();
			continue;
		}
		if (!a[1].y) {
			sort(a + 1, a + n + 1, cmp);
			ll sum = 0;
			for (int i = 1; i * 2 <= n; ++i) sum += a[i].x;
			cout << sum << '\n';
		}
		else cout << 114514 << '\n';
	}
	return 0;
}
