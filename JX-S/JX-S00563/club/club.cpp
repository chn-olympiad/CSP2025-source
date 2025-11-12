#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int N = 1e5 + 5;
struct node {
	int v[3], mp;
} a[N];
int T, n;
priority_queue<pii, vector<pii>, greater<pii>> q[3];
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 1; i <= n; ++i) {
			for (int j = 0; j < 3; ++j)
				cin >> a[i].v[j];
			a[i].mp = 0;
			for (int j = 1; j < 3; ++j)
				if (a[i].v[j] > a[i].v[a[i].mp])
					a[i].mp = j;
		}
		sort(a + 1, a + n + 1, [](const node& x, const node& y){return x.v[x.mp] > y.v[y.mp];});
		for (int i = 0; i < 3; ++i)
			while (!q[i].empty()) q[i].pop();
		long long ans = 0;
		for (int i = 1; i <= n; ++i) {
			int p = a[i].mp;
			int se = 0;
			for (int j = 0; j < 3; ++j)
				if (j != p) se = max(se, a[i].v[j]);
			if (q[p].size() == n / 2) {
				pii tmp = q[p].top();
				int u = tmp.second, d = tmp.first;
				if (tmp.first < a[i].v[a[i].mp] - se) {
					ans += a[i].v[p] - tmp.first;
					q[p].pop();
					q[p].emplace(a[i].v[p] - se, i);
				} else {
					ans += se;
				}
			} else {
				q[p].emplace(a[i].v[p] - se, i);
				ans += a[i].v[p];
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
/*
g++ club.cpp -o club -O2 -std=c++14 -static
*/