#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ls(p) p << 1
#define rs(p) p << 1 | 1

const int N = 1e5 + 5;
const int P = 1e9 + 7;
const int INF = 1e18;

int n, a[N][5], cnt[5], ans, mx[N], pmx[N];
vector <int> v[5];

bool cmp (int x, int y) {
	return mx[x] - pmx[x] < mx[y] - pmx[y];
}

void solve () {
	memset (mx, 0, sizeof mx);
	memset (pmx, 0, sizeof pmx);
	memset (cnt, 0, sizeof cnt);
	ans = 0;
	for (int i = 1; i <= 3; i++) v[i].clear();
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i][1] >> a[i][2] >> a[i][3];
	for (int i = 1; i <= n; i++) {
		int Mx = max (a[i][1], max(a[i][2], a[i][3]));
		if (a[i][1] == Mx) v[1].push_back(i), cnt[1]++, ans += Mx, mx[i] = Mx;
		else if (a[i][2] == Mx) v[2].push_back(i), cnt[2]++, ans += Mx, mx[i] = Mx;
		else v[3].push_back(i), cnt[3]++, ans += Mx, mx[i] = Mx;
		bool flag = true;
		for (int j = 1; j <= 3; j++) {
			if (a[i][j] == Mx && flag) {
				flag = false;
				continue;
			}
			pmx[i] = max (pmx[i], a[i][j]);
		}
	}
	for (int i = 1; i <= 3; i++) {
		if (cnt[i] <= (n >> 1)) continue;
		sort (v[i].begin(), v[i].end(), cmp);
		for (int j = 1; j <= cnt[i] - (n >> 1); j++) {
			ans -= (mx[v[i][j - 1]] - pmx[v[i][j - 1]]);
		}
		break;
	}
	cout << ans << "\n";
}

signed main () {
	freopen ("club.in", "r", stdin);
	freopen ("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T = 1; cin >> T;
	while (T--) solve ();
	return 0;
}