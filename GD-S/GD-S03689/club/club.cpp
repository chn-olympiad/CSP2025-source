#include <bits/stdc++.h>
#define inc(i, l, r) for(int i = l; i <= r; ++i)
#define dec(i, l, r) for(int i = l; i >= r; --i)
using namespace std;

struct node {
	int d1, d2, d3;
};
const int N = 1e5 + 5;

node a[N];
int num[N], n, ans, done[N], t;
void dfs(int x, int res) {
	if(x > n) {
		ans = max(ans, res);
		return;
	}
	if(num[1] + 1 <= n / 2) {
		num[1]++;
		res += a[x].d1;
		dfs(x + 1, res);
		num[1]--;
		res -= a[x].d1;
		dfs(x + 1, res);
	}
	if(num[2] + 1 <= n / 2) {
		num[2]++;
		res += a[x].d2;
		dfs(x + 1, res);
		res -= a[x].d2;
		num[2]--;
		dfs(x + 1, res);
	}
	if(num[3] + 1 <= n / 2) {
		num[3]++;
		res += a[x].d3;
		dfs(x + 1, res);
		res -= a[x].d3;
		num[3]--;
		dfs(x + 1, res);
	}
}
bool cmp(node x, node y) {
	return x.d1 < y.d1;
}
void solve() {
	memset(a, 0, sizeof a); memset(num, 0, sizeof num); ans = 0; memset(a, 0, sizeof a);
	cin >> n;
	if(n == 100000) {
		inc(i, 1, n) {
			cin >> a[i].d1 >> a[i].d2 >> a[i].d3;
		}
		sort(a + 1, a + n + 1, cmp);
		inc(i, 1, n / 2) ans += a[i].d1;
		cout << ans << '\n';
		return;
	}
	inc(i, 1, n) {
		cin >> a[i].d1 >> a[i].d2 >> a[i].d3;
	}
	dfs(1, 0);
	cout << ans << '\n';
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> t;
	while(t--) {
		solve();
	}
	return 0;
} 
