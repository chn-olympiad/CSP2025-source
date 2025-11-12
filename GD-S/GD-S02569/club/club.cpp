#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
array<int, 3> a[N];
priority_queue<array<int, 3>> q;
bitset<N> vis;
int cnt[3];
int n;
inline void sol() {
	memset(cnt, 0, sizeof cnt);
	while (!q.empty())
		q.pop();
	vis.reset();
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int& j : a[i])
			cin >> j;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int tmp = a[i][0] + a[i][1] + a[i][2] - *max_element(a[i].begin(), a[i].end()) - *min_element(a[i].begin(), a[i].end());
		ans += tmp;
		for (int& j : a[i])
			j -= tmp;
	}
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < 3; j++)
			q.push({a[i][j], i, j});
	while (!q.empty()) {
		array<int, 3> u = q.top();
		q.pop();
		if (vis[u[1]] || cnt[u[2]] >= n / 2)
			continue;
		ans += u[0];
		vis.set(u[1]);
		cnt[u[2]]++;
	}
	cout << ans << '\n';
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while (T--)
		sol();
}