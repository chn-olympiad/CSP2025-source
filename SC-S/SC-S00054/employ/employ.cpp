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

int n, m, c[505], p[505], sum, ans;
string s;

void solve() {
	cin >> n >> m >> s;
	s = " " + s;
	rep(i, 1, n) {
		cin >> c[i];
	}
	rep(i, 1, n) {
		p[i] = i;
	}
	do {
		sum = 0;
		rep(i, 1, n) {
			if(s[i] == '0' or sum >= c[p[i]]) {
				++sum;
			}
		}
		if(n - sum >= m) ++ans;
	} while(next_permutation(p + 1, p + 1 + n));
	cout << ans << endl;
	return;
}

signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int T = 1;
	while(T--) solve();
	return 0;
}