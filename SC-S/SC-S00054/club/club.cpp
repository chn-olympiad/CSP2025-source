#include<bits/stdc++.h>

#define rep(i, s, e) for(int (i) = (s); (i) <= (e); ++(i))
#define fep(i, s, e) for(int (i) = (s); (i) < (e); ++(i))
#define _rep(i, s, e) for(int (i) = (s); (i) >= (e); --(i))
#define _fep(i, s, e) for(int (i) = (s); (i) > (e); --(i))

// #define int long long
#define pii pair<int, int>

using namespace std;

constexpr int inf = numeric_limits<int>::max() / 2;
constexpr int ninf = numeric_limits<int>::min() / 2;
constexpr int mod = 998244353;
constexpr double eps = 1e-9;

int n, a[100005][4], d[100005], cnt[4], ans, id, mx, m, b[100005];

void solve() {
	cin >> n;
	rep(j, 1, 3) {
		cnt[j] = 0;
	}
	ans = 0;
	rep(i, 1, n) {
		a[i][d[i] = 0] = ninf;
		rep(j, 1, 3) {
			cin >> a[i][j];
			if(a[i][j] > a[i][d[i]]) {
				d[i] = j;
			}
		}
		ans += a[i][d[i]];
		++cnt[d[i]];
	}
	id = 0;
	rep(j, 1, 3) {
		if(cnt[j] > n / 2) {
			id = j;
			break;
		}
	}
	if(id) {
		m = 0;
		rep(i, 1, n) {
			if(d[i] == id) {
				mx = 0;
				rep(j, 1, 3) {
					if(j == id) continue;
					mx = max(mx, a[i][j]);
				}
				b[++m] = a[i][id] - mx;
			}
		}
		sort(b + 1, b + 1 + m);
		rep(i, 1, cnt[id] - n / 2) {
			ans -= b[i];
		}
	}
	cout << ans << endl;
	return;
}

signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int T = 1; cin >> T;
	while(T--) solve();
	return 0;
}