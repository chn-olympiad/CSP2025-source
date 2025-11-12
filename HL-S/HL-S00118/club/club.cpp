#include <bits/stdc++.h>

using namespace std;

constexpr int N = 1e5;

int test, n;
array<int, 3> a[N + 1];
vector<int> vec[3];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> test;
	while (test--) {
		cin >> n;
		for (int i = 0; i < 3; i++)
			vec[i].clear();
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			int id = 0;
			vector<int> tmp;
			for (int j = 0; j < 3; j++) {
				cin >> a[i][j];
				if (a[i][j] > a[i][id])
					id = j;
				tmp.push_back(a[i][j]);
			}
			sort(tmp.begin(), tmp.end());
			ans += tmp[2];
			vec[id].push_back(tmp[2] - tmp[1]);
		}
		int id = 0;
		for (int i = 1; i < 3; i++)
			if (vec[i].size() > vec[id].size())
				id = i;
		if (vec[id].size() <= n / 2)
			cout << ans << '\n';
		else {
			sort(vec[id].begin(), vec[id].end());
			for (int i = 1; i <= vec[id].size() - n / 2; i++)
				ans -= vec[id][i - 1];
			cout << ans << '\n';
		}
	}
	return 0;
}