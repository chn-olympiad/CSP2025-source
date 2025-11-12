#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define endl '\n'
using namespace std;
const int maxn = 1e5 + 5;
// 最多的只能有一个 
int n;
int a[maxn][4];
int cnt[4];
void solve() {
	cin >> n;
	cnt[1] = cnt[2] = cnt[3] = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d%d%d", &a[i][1], &a[i][2], &a[i][3]);
	}
	priority_queue<pii, vector<pii>, greater<pii>> q;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int mx = 1e9, sc = 1e9, mxi = 0, sci = 0;
		if (a[i][1] > a[i][2]) {
			mx = a[i][1];
			mxi = 1;
			sci = 2;
			sc = a[i][2];
		}
		else {
			mx = a[i][2];
			mxi = 2;
			sci = 1;
			sc = a[i][1];
		}
		if (a[i][3] > mx) {
			sci = mxi;
			sc = mx;
			mx = a[i][3];
			mxi = 3;
		}
		else if (a[i][3] > sc) {
			sc = a[i][3];
			sci = 3;
		}
//		cout << mx << ' ' << mxi << ' ' << sc << ' ' << sci << endl; 
		cnt[mxi]++;
		q.push({mx - sc, mxi});
//		if (mxi == 3)
//		cout << mx - sc << endl;
		ans += mx;
	}
	if (max({cnt[1], cnt[2], cnt[3]}) > n / 2) {
		int now = 0, mx = 0;
		if (cnt[1] > mx) mx = cnt[1], now = 1;
		if (cnt[2] > mx) mx = cnt[2], now = 2;
		if (cnt[3] > mx) mx = cnt[3], now = 3;
//		cout << now << endl;
		while (!q.empty() && cnt[now] > n / 2) {
			int x = q.top().first, i = q.top().second;
			q.pop();
			if (i != now) continue;
			ans -= x;
			cnt[now]--;
//			cout << x << endl;
		}
	}
	cout << ans << endl;
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	cin >> T; 
	while (T--) solve();
} 
