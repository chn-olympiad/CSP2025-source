#include <bits/stdc++.h>

#define rep(i, j, k) for(int i = (j); i <= (k); ++i)
#define dwn(i, j, k) for(int i = (j); i >= (k); --i)
#define int long long
#define ull unsigned long long
#define endl '\n'

using namespace std;

constexpr int N = 1e6 + 7;

pair<int, int> a1[N], a2[N], a3[N];

int a[N][4], cnt1[N], cnt2[N], cnt3[N], flag[4];

int cmp(pair<int, int> x, pair<int, int> y) {return x.first - x.second > y.first - y.second;}

void solve() {
	flag[1] = flag[2] = flag[3] = 0;
	int n, res = 0;
	cin >> n;
	rep(i, 1, n) {
		rep(j, 1, 3) cin >> a[i][j];
		a1[i].first = a[i][1], a1[i].second = max(a[i][2], a[i][3]);
		a2[i].first = a[i][2], a2[i].second = max(a[i][1], a[i][3]);
		a3[i].first = a[i][3], a3[i].second = max(a[i][1], a[i][2]);
		if(a[i][1] >= a[i][2] && a[i][1] >= a[i][3]) {
			res += a[i][1];
			if(a[i][1] != a[i][2] && a[i][1] != a[i][3]) ++flag[1];
		} else if(a[i][2] >= a[i][1] && a[i][2] >= a[i][3]) {
			res += a[i][2];
			if(a[i][2] != a[i][1] && a[i][2] != a[i][3]) ++flag[2]; 
		} else {
			res += a[i][3];
			if(a[i][3] != a[i][1] && a[i][3] != a[i][2]) ++flag[3];
		}
	}
	if(flag[1] <= n / 2 && flag[2] <= n / 2 && flag[3] <= n / 2) {
		cout << res << endl;
		return;
	}
	sort(a1 + 1, a1 + n + 1, cmp), sort(a2 + 1, a2 + n + 1, cmp), sort(a3 + 1, a3 + n + 1, cmp);
	int ans1 = 0, ans2 = 0, ans3 = 0;
	rep(i, 1, n / 2) ans1 += a1[i].first;
	rep(i, n / 2 + 1, n) ans1 += a1[i].second;
	rep(i, 1, n / 2) ans2 += a2[i].first;
	rep(i, n / 2 + 1, n) ans2 += a2[i].second;
	rep(i, 1, n / 2) ans3 += a3[i].first;
	rep(i, n / 2 + 1, n) ans3 += a3[i].second;
	cout << max(ans1, max(ans2, ans3)) << endl;
}

signed main() {
	freopen("club.in", "r", stdin), freopen("club.out", "w", stdout);
	ios :: sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
