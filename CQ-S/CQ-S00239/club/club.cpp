#include<bits/stdc++.h>
using namespace std;
const int N = 100010;
int a[N][3], id[N], num[3];
signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;cin >> T;
	while (T -- ) {
		int n;cin >> n;
		int ans = 0;
		num[0] = num[1] = num[2] = 0;
		for (int i = 1; i <= n; i ++ ) for (int j = 0; j < 3; j ++ ) cin >> a[i][j];
		for (int i = 1; i <= n; i ++ ) {
			if (a[i][0] >= a[i][1] && a[i][0] >= a[i][2]) id[i] = 0;
			else if (a[i][1] >= a[i][0] && a[i][1] >= a[i][2]) id[i] = 1;
			else id[i] = 2;
			ans += a[i][id[i]], num[id[i]] ++;
		}
		int x = 0;
		if (num[1] >= max(num[0], num[2])) x = 1;
		else if (num[2] >= max(num[0], num[1])) x = 2;
		if (num[x] > n / 2) {
			vector<int> s;
			for (int i = 1; i <= n; i ++ ) if (id[i] == x) {
				int mi = 1e9;
				for (int j = 0; j < 3; j ++ ) if (j != x) mi = min(mi, a[i][x] - a[i][j]);
				s.push_back(mi);
			}
			sort(s.begin(), s.end());
			for (int i = 0; i < num[x] - n / 2; i ++ ) ans -= s[i];
		}
		cout << ans << '\n';
	}
	return 0;
}
