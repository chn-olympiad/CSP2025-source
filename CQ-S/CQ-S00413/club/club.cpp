#include<bits/stdc++.h>
#define ll long long
#define rep(i, x, y) for(int i = (x); i <= (y); ++i)
#define drep(i, x, y) for(int i = (x); i >= (y); --i)
#define pb push_back
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define pii pair<int, int>
#define fi first
#define se second
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
inline void Fin(string s) { freopen((s + ".in").c_str(), "r", stdin); }
inline void Fout(string s) { freopen((s + ".out").c_str(), "w", stdout); }
const int N = 100010;
int n, a[N][3], cnt[3], d[N]; ll ans;
vector<int> vec[3];
inline void solve() {
	cin >> n, ans = 0;
	rep(j, 0, 2) vec[j].clear(), cnt[j] = 0;
	rep(i, 1, n) {
		rep(j, 0, 2) cin >> a[i][j];
		int p = 0;
		rep(j, 0, 2) if(a[i][j] > a[i][p]) p = j;
		vec[p].pb(i);
		ans += a[i][p], d[i] = 1e9;
		rep(j, 0, 2) if(j != p) d[i] = min(d[i], a[i][p] - a[i][j]);
	}
	rep(j, 0, 2) if(vec[j].size() > (n >> 1)) {
		sort(ALL(vec[j]), [&](int x, int y) { return d[x] < d[y]; });
		rep(i, 0, SZ(vec[j]) - (n >> 1) - 1) ans -= d[vec[j][i]];
	}
	cout << ans << '\n';
}
int main() {
	Fin("club"), Fout("club");
	fastio; int T; cin >> T;
	while(T--) solve();
	return 0;
}

