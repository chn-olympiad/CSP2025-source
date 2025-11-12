#include <iostream>
#include <algorithm>
#include <queue>
//#define int long long

using namespace std;

const int MaxN = 1e5 + 10;

struct S {
	int x, y;
	
	bool operator<(const S &j) const {
		return x == j.x ? y > j.y : x > j.x; 
	} 
} c[MaxN];

int a[MaxN][3], n, t, ans;
priority_queue<int> q;

void Work(int op, int res = 0, int cnt = 0) {
	priority_queue<int>().swap(q);
	for (int i = 1; i <= n; i++) {
		c[i].y = 0;
		for (int j = 0; j <= 2; j++) {
			if (op == j) c[i].x = a[i][j];
			else c[i].y = max(c[i].y, a[i][j]);
		}
	}
	sort(c + 1, c + n + 1);
	for (int i = 1; i <= n; i++) {
		if (c[i].x > c[i].y) { // 加入指定 n/2 社团 
			if (cnt == n / 2) {
				if (res + q.top() + c[i].x > res + c[i].y) {
					res += q.top() + c[i].x;
					q.pop();
					q.push(c[i].y - c[i].x);
				} else {
					res += c[i].y;
				}
			} else {
				q.push(c[i].y - c[i].x);
				res += c[i].x, cnt++;
			}
		} else {
			res += c[i].y;
		}
	}
	if (cnt == n / 2) ans = max(ans, res);
}

signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	for (cin >> t; t; t--) {
		cin >> n, ans = 0;
		for (int i = 1; i <= n; i++) {
			cin >> a[i][0] >> a[i][1] >> a[i][2];
		}
		Work(0), Work(1), Work(2);
		if (ans == 0) { // 说明可以随便放
			for (int i = 1; i <= n; i++) {
				ans += max(a[i][0], max(a[i][1], a[i][2]));
			} 
		} 
		cout << ans << '\n';
	}
	return 0;
}
