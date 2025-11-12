#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 1e5 + 5;

int a[N][4];
vector<int> x[4];
int f[N];

signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	int T; cin >> T;
	while (T --) {
		int n; cin >> n;
		for (int i = 1; i <= n; i ++) cin >> a[i][1] >> a[i][2] >> a[i][3];
		int res = 0;
		for (int i = 1; i <= n; i ++) {
			int mx = max({a[i][1], a[i][2], a[i][3]});
			if (mx == a[i][1]) x[1].push_back(i);
			else if (mx == a[i][2]) x[2].push_back(i);
			else x[3].push_back(i);
			res += mx;
		}
		int id = 0;
		if ((int)x[1].size() > n / 2) id = 1;
		else if ((int)x[2].size() > n / 2) id = 2;
		else if ((int)x[3].size() > n / 3) id = 3;
		if (!id) cout << res << endl;
		else {
			int cnt = x[id].size();
			for (int i = 1; i <= cnt; i ++) {
				int j = x[id][i - 1];
				if (id == 1) f[i] = a[j][1] - max(a[j][2], a[j][3]);
				else if (id == 2) f[i] = a[j][2] - max(a[j][1], a[j][3]);
				else f[i] = a[j][3] - max(a[j][1], a[j][2]);
			}
			sort(f + 1, f + cnt + 1);
			for (int i = 1; i <= cnt - n / 2; i ++) res -= f[i];
			cout << res << endl;
		}
		x[1].clear(), x[2].clear(), x[3].clear();
		for (int i = 1; i <= n; i ++) f[i] = 0;
	}
	return 0;
} 
