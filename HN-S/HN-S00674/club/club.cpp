#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 10;
ll ans, n, q, vis[N], sum[4];
struct node {
	int res, id;
	bool operator < (node other) const {
		return other.res < res;
	}
}a[4];
priority_queue<pair<int, int>> s[4];
pair<int, int> x[N], y[N], z[N];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> q;
	while (q--) {
		cin >> n;
		sum[1] = sum[2] = sum[3] = ans = 0;
		for (int i = 1; i <= n; i++) x[i] = y[i] = z[i] = {0, 0};
		for (int i = 1; i <= 3; i++) {
			while (!s[i].empty()) s[i].pop();
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= 3; j++) {
				cin >> a[j].res;
				a[j].id = j;
			}
			sort(a + 1, a + 1 + 3);
			x[i] = {a[1].res, a[1].id};
			y[i] = {a[2].res, a[2].id};
			z[i] = {a[3].res, a[3].id};
			s[a[1].id].push({a[2].res - a[1].res, i});
			ans += a[1].res;
		} 
		int pos = 0;
		for (int i = 1; i <= 3; i++) if (s[i].size() >= (n/2)) pos = i;
		if (pos != 0) {
			for (int i = 1; i <= (n/2) - s[pos].size(); i++) {
				int res = s[pos].top().first, u = s[pos].top().second;
				ans += res;
				s[pos].pop();
				s[y[u].second].push({z[u].first - y[u].first, u});
			}
		}
		for (int i = 1; i <= 3; i++) if (s[i].size() >= (n/2)) pos = i;
		if (pos != 0) {
			for (int i = 1; i <= (n/2) - s[pos].size(); i++) {
				ans += s[pos].top().first;
				s[pos].pop();
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
