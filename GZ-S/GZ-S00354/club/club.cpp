//GZ-S00354 程泊郡 安顺市第二高级中学 
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

const int N = 1e5 + 10;
int p[N][3];
int t, n;
vector<int> c[3];
long long ans;
long long ans2;

void solve() {
	cin >> n;
	int t = 0;
	ans = ans2 = 0;
	c[1].clear();
	c[2].clear();
	c[0].clear();
	for (int i = 1; i <= n; i++) {
		cin >> p[i][0] >> p[i][1] >> p[i][2];
		int res = max(p[i][1], p[i][2]);
		res = max(res, p[i][0]);
		if (res == p[i][0]) {
			c[0].push_back(i);
		}
		else if (res == p[i][1]) {
			c[1].push_back(i);
		}
		else if (res == p[i][2]) {
			c[2].push_back(i);
		}
	}
	for (int i = 0; i < 3; i++) {
		if (c[i].size() > n / 2) {
			int m = c[i].size();
			for (ull j = 1; j < (1 << m); j++) {
				long long ret = 0;
				int op = 0;
				for (int k = 0; k < m; k++) {
					int o = c[i][k];
					if ((j >> k) & 1) {
						int ma = max(p[o][0], p[o][1]);
						ma = max(ma, p[o][2]);
						ret += ma;
						op++;
					}
					else {
						int ma = max(p[o][0], p[o][1]);
						ma = max(ma, p[o][2]);
						int mi = min(p[o][0], p[o][1]);
						mi = min(mi, p[o][2]);
						long long mia = p[o][0] + p[o][1] + p[o][2];
						mia = mia - mi - ma;
						ret += mia;
					}
				}
				if (op > n / 2) continue;
				ans2 = max(ans2, ret);
			}
		}
		else if (c[i].size() <= n / 2 && c[i].size() >= 1){
			for (int j = 0; j < c[i].size(); j++) {
				int ma = max(p[c[i][j]][0], p[c[i][j]][1]);
				ma = max(ma, p[c[i][j]][2]);
				ans += ma;
			}
		}
	}
	cout << ans + ans2 << '\n';
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	for (int i = 1; i <= t; i++) {
		solve();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}