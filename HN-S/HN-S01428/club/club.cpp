#include <bits/stdc++.h>
using namespace std;
#define N 100011
struct node {
	int vl, id, dl, vl2;
	bool operator < (const node &b)
	const {
		if(vl == b.vl)
			return vl2 < b.vl2;
		return vl < b.vl;
	}
	bool operator > (const node &b)
	const {
		if(vl == b.vl)
			return vl2 > b.vl2;
		return vl > b.vl;
	}
};
priority_queue<node, vector<node>, greater<node>> q[3];
node a[N][10];
int n;
int ans;
void add(int ps) {
	for (int j = 0; j < 3; j++)
	{
		int id = a[ps][j].id;
		int vl = a[ps][j].vl;
		int vl2 = vl - a[ps][j + 1].vl;
		int vl3 = a[ps][j + 1].vl - a[ps][j + 2].vl;
		if (q[id].size() < n / 2)
		{
			q[id].push({vl2, ps, vl, vl3});
			ans += vl;
			break;
		}
		if (vl2 > q[id].top().vl)
		{
			int tmp = q[id].top().id;
			ans -= q[id].top().dl;
			q[id].pop();
			q[id].push({vl2, ps, vl, vl3});
			ans += vl;
			add(tmp);
			break;
		}
	}
}
void solve() {
	for (int i = 0; i < 3; i++)
		while (q[i].size())
			q[i].pop();
	ans = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> a[i][j].vl;
			a[i][j].id = j;
		}
		sort(a[i], a[i] + 3, greater<node>());
		add(i);
	}
	cout << ans << '\n';
}
int t;
signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--)
		solve();
	return 0;
}

