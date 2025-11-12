#include <bits/stdc++.h>
#define rep(i,a,b) for (int i = (a); i <= (b); ++ i)
#define per(i,a,b) for (int i = (a); i >= (b); -- i)
#define ll long long
#define INF 0x3f3f3f3f
#define llINF 0x3f3f3f3f3f3f3f3fLL

using namespace std;

int T, n, a[100010][3], val[100010], p[100010];
pair<int, int> ma[100010][2];

void solve() {
	cin >> n;
	int ans = 0, cnt[3] = {0, 0, 0};
	rep (i,1,n) {
		ma[i][0] = ma[i][1] = make_pair(-INF, 0);
		rep (j,0,2) cin >> a[i][j];
		rep (j,0,2) if (a[i][j] > ma[i][0].first) ma[i][1] = ma[i][0], ma[i][0] = make_pair(a[i][j], j);else if (a[i][j] > ma[i][1].first) ma[i][1] = make_pair(a[i][j], j);
		ans += ma[i][0].first;
		++ cnt[ma[i][0].second];
	}
	rep (i,1,n) val[i] = ma[i][1].first - ma[i][0].first, p[i] = i;
	sort(p + 1, p + n + 1, [&] (int x, int y) { return val[x] > val[y]; });
	rep (i,1,n) if (cnt[ma[p[i]][0].second] > n / 2) -- cnt[ma[p[i]][0].second], ans += val[p[i]];
	cout << ans << '\n';
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin.tie(nullptr) -> sync_with_stdio(false);
	cin >> T;
	while (T --) solve();
	return 0;
}

//Ren5Jie4Di4Ling5%