#include <bits/stdc++.h>
using namespace std;
int n, a[100005][3], w[100005], ans;
vector<int> v[3];
inline bool cmp(int x, int y) { return w[x] < w[y]; }
void solve() {
	cin >> n;
	v[0].clear(), v[1].clear(), v[2].clear(), ans = 0;
	for (int i = 1; i <= n; i++)
		cin >> a[i][0] >> a[i][1] >> a[i][2];
	for (int i = 1; i <= n; i++) {
		int tmp[3] = {a[i][0], a[i][1], a[i][2]};
		sort(tmp, tmp + 3);
		w[i] = tmp[1] - tmp[2];
		ans += tmp[2];
		if (a[i][0] == tmp[2]) {
			v[0].push_back(i);
		}
		else if (a[i][1] == tmp[2]) {
			v[1].push_back(i);
		}
		else {
			v[2].push_back(i);
		}
	}
	int tmp = n / 2;
	sort(v[0].begin(), v[0].end(), cmp);
	sort(v[1].begin(), v[1].end(), cmp);
	sort(v[2].begin(), v[2].end(), cmp);
	while (v[0].size() > tmp) {
		ans += w[v[0].back()];
		v[0].pop_back();
	}
	while (v[1].size() > tmp) {
		ans += w[v[1].back()];
		v[1].pop_back();
	}
	while (v[2].size() > tmp) {
		ans += w[v[2].back()];
		v[2].pop_back();
	}
	cout << ans << '\n';
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios :: sync_with_stdio(0);
	cin.tie(0), cout.tie(0); 
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
	return 0;
} 
