#include <bits/stdc++.h>
using namespace std;

namespace Creeper{
	const int N = 1e5 + 5;
	int n, ans;
	struct node {
		int d[5];
		int o1, o2, o3; 
		int i;
		bool operator<(const node& o) const {
			return (o1 - o2) > (o.o1 - o.o2);
		}
	}a[N], b[N];
	priority_queue<node> q[5];
	
	void solve() {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i].d[1] >> a[i].d[2] >> a[i].d[3];
			int o1 = 1, o2 = 2, o3 = 3;
			if (a[i].d[o2] > a[i].d[o1]) swap(o1, o2);
			if (a[i].d[o3] > a[i].d[o1]) swap(o3, o1);
			if (a[i].d[o3] > a[i].d[o2]) swap(o3, o2);
			a[i].i = i;
			a[i].o1 = a[i].d[o1];
			a[i].o2 = a[i].d[o2];
			a[i].o3 = a[i].d[o3];
			b[i].o1 = o1;
			b[i].o2 = o2;
			b[i].o3 = o3;
		}
		while (!q[1].empty()) q[1].pop();
		while (!q[2].empty()) q[2].pop();
		while (!q[3].empty()) q[3].pop();
		ans = 0;
		for (int i = 1; i <= n; i++) {
			int x = b[i].o1;
			if (q[x].size() == n / 2) {
//				cout << i << ' ' << x << '\n';
				int res1 = 0, res2 = 0;
				node u = q[x].top();
				res1 = ans - u.o1 + u.o2 + a[i].o1;
				res2 = ans + a[i].o2;
				if (res1 > res2) {
//					cout << i << ' ' << b[i].o1 << '\n';
					ans = res1;
					q[x].pop();
//					cout << u.i << ' ' << b[u.i].o2 << '\n';
					q[b[u.i].o2].push(u);
					q[x].push(a[i]);
				} else {
//					cout << i << ' ' << b[i].o2 << '\n';
					ans = res2;
					q[b[i].o2].push(u);
				}
			} else {
//				cout << i << '\n';
//				cout << i << ' ' << b[i].o1 << '\n';
				ans += a[i].o1;
				q[x].push(a[i]);
			}
//			cout << ans << '\n';
		}
		cout << ans << '\n';
	}
}

signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T = 1;
	cin >> T;
	while (T--) Creeper::solve(); 
}
