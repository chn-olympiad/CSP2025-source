// 100pts
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int kMaxN = 2e5 + 5;

int T, n, a[kMaxN][5], cnt[5], c[kMaxN];

void solve() {
	cin >> n;
	cnt[1] = cnt[2] = cnt[3] = 0;
	int ans = 0;
	priority_queue<int, vector<int>, greater<int> > q;
	for(int i = 1; i <= n; i++) {
		cin >> a[i][1] >> a[i][2] >> a[i][3];
		int x = max({a[i][1], a[i][2], a[i][3]});
		if(a[i][1] == x) {
			cnt[1]++, c[i] = 1;
		} else if(a[i][2] == x) {
			cnt[2]++, c[i] = 2;
		} else {
			cnt[3]++, c[i] = 3;
		}
		ans += x;
	}
	int ggbond = 0;
	for(int i = 1; i <= 3; i++) {
		if(cnt[i] > n / 2) ggbond = i;
	}
	if(ggbond) {
		for(int i = 1; i <= n; i++) {
			if(c[i] != ggbond) continue;
			int mx = 0;
			for(int j = 1; j <= 3; j++) {
				if(j != ggbond) mx = max(mx, a[i][j]);
			}
			q.push(a[i][ggbond] - mx);
		}
		for(int i = 1; i <= cnt[ggbond] - n / 2; i++) {
			ans -= q.top(), q.pop();
		}
	}
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(0), cin.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	for(cin >> T; T; T--) solve();
	return 0;
} 
