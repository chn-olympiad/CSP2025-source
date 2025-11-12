#include <bits/stdc++.h>
#define LL long long
#define fi first
#define se second
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 1e5+5;
int T, n;
LL ans;
pair<int, int > a[maxn][5];
int cmp(pair<int, int > A, pair<int, int > B) {
	return A.fi > B.fi;
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> T;
	while (T--) {
		cin >> n;
		ans = 0;
		priority_queue<int > q[5];
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= 3; j++) {
				cin >> a[i][j].fi;
				a[i][j].se = j;
			}
			sort(a[i] + 1, a[i] + 4, cmp);
			ans += a[i][1].fi;
			q[a[i][1].se].push(-(a[i][1].fi - a[i][2].fi));
		}
		for (int i = 1; i <= 3; i++) {
			while ((int)q[i].size() > n / 2) {
				int now = q[i].top();
				q[i].pop();
				ans += now;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}