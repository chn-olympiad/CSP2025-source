#include <bits/stdc++.h>
using namespace std;
int getid(int n, vector <vector <int>>& p) {
	if (n <= 200)
		return 11;
	bool is12 = 1;
	for (int i = 1; i <= n; i ++)
		for (int j = 2; j <= 3; j ++)
			if (p[i][j] != 0)
				is12 = 0;
	if (is12)
		return 12;
	bool is14 = 1;
	for (int i = 1; i <= n; i ++)
		if (p[i][3] != 0)
			is14 = 0;
	if (is14)
		return 14;
	return 20;
}
void solve() {
	int n;
	cin >> n;
	vector <vector <int>> p(n + 1, vector <int> (4, 0));
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= 3; j ++)
			cin >> p[i][j];
	int id = getid(n, p);
	if (id == 11) {
		vector <vector <vector <int>>> now(n + 1
		, vector <vector <int>> (n + 1
		, vector <int> (n + 1, 0))),  last(n + 1
		, vector <vector <int>> (n + 1
		, vector <int> (n + 1, 0)));
		for (int i = 1; i <= n; i ++) {
			for (int j = 0; j <= n / 2; j ++) {
				for (int k = 0; k <= n / 2; k ++) {
					int l = i - j - k;
					if (l >= 0) {
						if (j > 0)
							now[j][k][l] = max(now[j][k][l], last[j - 1][k][l] + p[i][1]);
						if (k > 0)
							now[j][k][l] = max(now[j][k][l], last[j][k - 1][l] + p[i][2]);
						if (l > 0)
							now[j][k][l] = max(now[j][k][l], last[j][k][l - 1] + p[i][3]);
					}
				}
			}
			last = now;
		}
		int ans = 0;
		for (int j = 1; j <= n / 2; j ++)
			for (int k = 1; k <= n / 2; k ++) {
				int l = n - j - k;
				if (l <= n / 2)
					ans = max(ans, now[j][k][l]);
			}
		cout << ans << "\n";
		return ;
	}
	if (id == 12) {
		sort(p.begin() + 1, p.begin() + n + 1, [&](vector <int> x, vector <int> y) {return x[0] > y[0];});
		int ans = 0;
		for (int i = 1; i <= n / 2; i ++)
			ans += p[i][0];
		cout << ans << "\n";
		return ;
	}
	if (id == 14) {
		for (int i = 1; i <= n; i ++)
			p[i][0] = max(p[i][1], p[i][2]) - min(p[i][1], p[i][2]);
		sort(p.begin() + 1, p.begin() + n + 1, [&](vector <int> x, vector <int> y) {return x[0] > y[0];});
		
		for (int i = 1; i <= n; i ++)
			cout << p[i][1] << " " << p[i][2] << "\n";
		
		int cnt1 = 0, cnt2 = 0, ans = 0;
		for (int i = 1; i <= n; i ++) {
			if (cnt1 == n / 2) {
				cnt2 ++;
				ans += p[i][2];
				continue;
			}
			if (cnt2 == n / 2) {
				cnt1 ++;
				ans += p[i][1];
				continue;
			}
			if (p[i][1] > p[i][2] && cnt1 < n / 2) {
				cnt1 ++;
				ans += p[i][1];
			} else {
				cnt2 ++;
				ans += p[i][2];
			}
		}
		cout << ans << "\n";
	}
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t --)
		solve();
	return 0;
}
