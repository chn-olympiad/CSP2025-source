#include <bits/stdc++.h>
using namespace std;
struct node {
	long long x, id;
	bool operator < (const node &b) const {
		return x < b.x;
	}
};
long long ans;
priority_queue<node> q[3];
int t, n, a[100005][3], p[100005];
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	while(t--) {
		cin >> n, ans = 0;
		for(int i = 1; i <= n; i++) {
			p[i] = 0;
			for(int j = 0; j < 3; j++) {
				cin >> a[i][j];
				if(a[i][j] > a[i][p[i]])
					p[i] = j;
			}
			ans += a[i][p[i]];
			int mx = 0;
			for(int j = 0; j < 3; j++)
				if(j ^ p[i])
					mx = max(mx, a[i][j]);
			q[p[i]].push({mx - a[i][p[i]], i});
		}
		for(int i = 0; i < 3; i++)
			while(q[i].size() > (n >> 1)) {
				auto x = q[i].top();
				q[i].pop(), ans += x.x;
			}
		cout << ans << '\n';
		for(int i = 0; i < 3; i++)
			while(q[i].size())
				q[i].pop();
	}
	return 0;
}