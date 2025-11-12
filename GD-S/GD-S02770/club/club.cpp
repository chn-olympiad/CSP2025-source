#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e5;
int t;
int n;
int a[N + 5][3];
struct node {
	int p, val;
	constexpr bool operator <(const node &x) const {
		return val < x.val;
	}
} x[N + 5];
void solve() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d%d%d", &a[i][0], &a[i][1], &a[i][2]);
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += max({a[i][0], a[i][1], a[i][2]});
		int b[] = {a[i][0], a[i][1], a[i][2]};
		sort(b, b + 3, greater<int>());
		x[i] = {a[i][0] == b[0] ? 0 : a[i][1] == b[0] ? 1 : 2, b[0] - b[1]};
	}
	int cnt[3] = {};
	for (int i = 1; i <= n; i++) cnt[x[i].p]++;
	sort(x + 1, x + n + 1);
	for (int i = 1; i <= n; i++) {
		int p = x[i].p, val = x[i].val; 
		if (cnt[p] > n >> 1) {
			ans -= val;
			cnt[p]--;
		}
	}
	printf("%d\n", ans);
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &t);
	while (t--) solve();
	return 0;
} 

