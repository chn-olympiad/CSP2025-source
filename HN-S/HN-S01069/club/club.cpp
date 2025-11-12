#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
struct node {
	int x, id;
	bool flag;
} a[N][4];
bool cmp(node x, node y) {
	return x.x > y.x;
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, ans = 0;
		cin >> n;
		priority_queue<pair<int, pair<int, int> >, vector<pair<int, pair<int, int> > >, greater<pair<int, pair<int, int> > > > q[4];
		for (int i = 1; i <= 3; i++) {
			while (q[i].size() != 0) {
				q[i].pop();
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= 3; j++) {
				cin >> a[i][j].x;
				a[i][j].id = j;
				a[i][j].flag = 0;
			}
			sort(a[i] + 1, a[i] + 4, cmp);
			for (int j = 1; j <= 3; j++) {
				int id = a[i][j].id;
				if (q[id].size() == n / 2) {
					if (q[id].top().first >= a[i][j].x - a[i][j + 1].x) {
						continue;
					}
					int x = q[id].top().second.first;
					q[id].pop();
					for (int k = 1; k <= 3; k++) {
						if (!a[x][k].flag) {
							a[x][k].flag = 1;
							q[a[x][k].id].push({a[x][k].x - a[x][k + 1].x, {x, k}});
							break;
						}
					}
				}
				q[id].push({a[i][j].x - a[i][j + 1].x, {i, j}});
				a[i][j].flag = 1;
				break;
			}
		}
		for (int i = 1; i <= 3; i++) {
			while (q[i].size() != 0) {
				ans += a[q[i].top().second.first][q[i].top().second.second].x;
//				cout << a[q[i].top().second.first][q[i].top().second.second].x << ' ';
				q[i].pop();
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
//
//1
//4
//0 1 0
//0 1 0
//0 2 0
//0 2 0

