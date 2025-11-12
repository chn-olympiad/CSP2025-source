#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 100100;
int n;
int a[N][3];
vector<int> ve[3];

void solve() {
	for (int i = 0; i < 3; i++) {
		ve[i].clear();
	}
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d%d", &a[i][0], &a[i][1], &a[i][2]);
	}
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		int mx = max({a[i][0], a[i][1], a[i][2]});
		ans += mx;
		if (a[i][0] == mx) {
			ve[0].push_back(mx - max(a[i][1], a[i][2]));
		} else if (a[i][1] == mx) {
			ve[1].push_back(mx - max(a[i][0], a[i][2]));
		} else {
			ve[2].push_back(mx - max(a[i][0], a[i][1]));
		}
	}
	for (int i = 0; i < 3; i++) {
		if (((int)ve[i].size()) > n / 2) {
			sort(ve[i].begin(), ve[i].end());
			reverse(ve[i].begin(), ve[i].end());
			while (((int)ve[i].size()) > n / 2) {
				ans -= ve[i].back();
				ve[i].pop_back();
			}
		}
	}
	printf("%lld\n", ans);
}

int main() {
	freopen("club.in", "r", stdin);	freopen("club.out", "w", stdout);
	int T;
	scanf("%d", &T);
	while (T--) {
		solve();
	}
	return 0;
}