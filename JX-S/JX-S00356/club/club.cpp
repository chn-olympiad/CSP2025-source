#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 5;

int a[N][3], cnt[3];

void solve() {
	int n; cin >> n;
	cnt[0] = cnt[1] = cnt[2] = 0;
	for(int i = 1; i <= n; i++)
		cin >> a[i][0] >> a[i][1] >> a[i][2];
	for(int i = 1; i <= n; i++)
		if(a[i][0] > a[i][1] && a[i][0] > a[i][2]) cnt[0]++;
		else if(a[i][1] > a[i][0] && a[i][1] > a[i][2]) cnt[1]++;
		else if(a[i][2] > a[i][0] && a[i][2] > a[i][1]) cnt[2]++;
	int ans = 0;
	if(max({cnt[0], cnt[1], cnt[2]}) <= n / 2) {
		for(int i = 1; i <= n; i++)
			ans += max({a[i][0], a[i][1], a[i][2]});
	} else {
		for(int i = 0; i < 3; i++) {
			if(cnt[i] > n / 2) {
				priority_queue<int> q;
				for(int j = 1; j <= n; j++) {
					if(a[j][i] > a[j][(i + 1) % 3] && a[j][i] > a[j][(i + 2) % 3])
						q.push(a[j][i] - max(a[j][(i + 1) % 3], a[j][(i + 2) % 3]));
					ans += max(a[j][(i + 1) % 3], a[j][(i + 2) % 3]);
				}
				for(int i = 1; i <= n / 2; i++) {
					ans += q.top(); q.pop();
				}
			}
		}
	}
	cout << ans << '\n';
}

signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> t;
	while(t--) {
		solve();
	}
	return 0;
}