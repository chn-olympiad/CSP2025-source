#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 5;
int n, a[N][4];
vector<int> vec[4];
signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		vec[1].clear(), vec[2].clear(), vec[3].clear();
		cin >> n;
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			pair<int, int> maxv = {-1, -1};
			maxv = max(maxv, {a[i][1], 1});
			maxv = max(maxv, {a[i][2], 2});
			maxv = max(maxv, {a[i][3], 3});
			ans += maxv.first;
			vec[maxv.second].push_back(i);
		}
		if (vec[1].size() > n / 2 || vec[2].size() > n / 2 || vec[3].size() > n / 2) {
			int p;
			if (vec[1].size() > n / 2) p = 1;
			if (vec[2].size() > n / 2) p = 2;
			if (vec[3].size() > n / 2) p = 3;
			int num = vec[p].size() - (n / 2);
			vector<int> vc;
			for (auto i : vec[p]) {
				pair<int, int> maxv = {-1, -1};
				maxv = max(maxv, {a[i][1], 1});
				maxv = max(maxv, {a[i][2], 2});
				maxv = max(maxv, {a[i][3], 3});
				pair<int, int> maxv1 = {-1, -1};
				if (p != 1) maxv1 = max(maxv1, {a[i][1], 1});
				if (p != 2) maxv1 = max(maxv1, {a[i][2], 2});
				if (p != 3) maxv1 = max(maxv1, {a[i][3], 3});
				vc.push_back(maxv1.first - maxv.first);
			}
			sort(vc.begin(), vc.end(), greater<int>());
			for (int i = 0; i < num; i++) ans += vc[i];
		}
		cout << ans << "\n";
	}
	return 0;
}
