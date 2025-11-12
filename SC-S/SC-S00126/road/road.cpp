#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6+9;
typedef pair<int, int> PII;
vector<PII> e[N];
int a[20][N];
bool v[N];
signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	if (k == 0) {
		for (int i = 1; i <= m; i++) {
			int u, v, w;
			cin >> u >> v >> w;
			e[u].push_back({v, w});
			e[v].push_back({u, w});
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			if (v[i]) continue;
			int mi = 0x3f3f3f3f, pos = -1;
			for (int j = 0; j < (int)e[i].size(); j++) {
				if ((e[i][j].second < mi) || ((e[i][j].second == mi) && (!v[e[i][j].first]))) {
					mi = e[i][j].second;
					pos = e[i][j].first;
				}
			}
			ans += mi;
			v[pos] = 1;
			v[i] = 1;
		}
		cout << ans << "\n";
		return 0;
	}
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		e[u].push_back({v, w});
		e[v].push_back({u, w});
	}
	for (int i = 1; i <= k; i++) {
		int x;
		cin >> x;
		for (int j = 1; j <= n; j++) cin >> a[i][j];
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (v[i]) continue;
		int mi = 0x3f3f3f3f, pos = -1;
		for (int j = 0; j < (int)e[i].size(); j++) {
			if ((e[i][j].second < mi) || ((e[i][j].second == mi) && (!v[e[i][j].first]))) {
				mi = e[i][j].second;
				pos = e[i][j].first;
			}
		}
		int mi2 = 0x3f3f3f3f, pos2 = -1;
		for (int j = 1; j <= k; j++) {
			for (int q = 1; q <= n; q++) {
				if (q != i) {
					if ((a[j][q] + a[j][i] < mi) || ((a[j][q] + a[j][i] == mi) && (!v[q]))) {
						mi2 = a[j][q] + a[j][i];
						pos2 = q;
					}
				}
			}
		}
		if (mi2 < mi) {
			mi = mi2;
			pos = pos2;
		}
		ans += mi;
		v[pos] = 1;
		v[i] = 1;
	}
	cout << ans << "\n";
	return 0;
}