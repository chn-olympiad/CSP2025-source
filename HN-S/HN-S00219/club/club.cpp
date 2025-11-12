#include <bits/stdc++.h>
#define LL long long

using namespace std;

const int N = 1e5 + 5;

int t, n, a[N][3], ans;
vector <int> v[3];

int main ()  {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	for (cin >> t; t--;) {
		cin >> n;
		ans = 0;
		for (int i = 0; i < 3; i++) v[i].clear();
		for (int i = 1; i <= n; i++) {
			cin >> a[i][0] >> a[i][1] >> a[i][2];
			for (int j = 0; j < 3; j++) {
				if (a[i][j] >= a[i][(j + 1) % 3] && a[i][j] >= a[i][(j + 2) % 3]) {
					v[j].emplace_back(a[i][j] - max(a[i][(j + 1) % 3], a[i][(j + 2) % 3]));
					ans += a[i][j];
					break;
				}
			}
		}
		for (int i = 0; i < 3; i++) {
			if (v[i].size() > n / 2) {
				sort(v[i].begin(), v[i].end());
				for (int j = 0; j < v[i].size() - n / 2; j++) {
					ans -= v[i][j];
				}
				break;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
