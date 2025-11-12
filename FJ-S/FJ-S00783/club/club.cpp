#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5;
int T;
int n, cnt[4];
pair<int, int> a[N+5][4];
bool cmp (pair<int, int> x, pair<int, int> y) {
	return x.first > y.first;
}
signed main () {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	while(T--){
		cin >> n;
		int ans = 0;
		for (int i = 1; i <= n; i ++) {
			for (int j = 1; j <= 3; j ++) {
				int t;
				cin >> t;
				a[i][j] = {t, j};
			}
			sort(a[i]+1, a[i]+4, cmp);
			ans += a[i][1].first;
		}
		cnt[1] = cnt[2] = cnt[3] = 0;
		for (int i = 1; i <= n; i ++) {
			cnt[a[i][1].second] ++;
		}
		vector<int> tmp;
		int maxgp = 0;
		for (int i = 1; i <= n; i ++) {
			if (cnt[a[i][1].second] > n / 2) {
				maxgp = a[i][1].second;
				tmp.emplace_back(a[i][1].first - a[i][2].first);
			}
		}
		if (maxgp) {
			sort(tmp.begin(), tmp.end());
			for (int i = 0; i < cnt[maxgp] - n/2; i ++) {
				ans -= tmp[i];
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
