#include <bits/stdc++.h>
#define fi first
#define sc second
#define pii pair<int, int>
#define deb(x) clog << #x << " : " << x << " "
#define debn(x) clog << #x << " : " << x << "\n"
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
const int mod = 998244353, iinf = 0x3f3f3f3f;
struct nd {
	int _1, _2, _3;
} a[N];
bool A, B, C;
int n, ans, cnt1, cnt2, cnt3;
int _1[N], _2[N], _3[N];
void dfs(int u, int s) {
	if (u == n + 1) {
		ans = max(ans, s);
		return;
	}
	if (cnt1 < (n >> 1)) {
		cnt1 ++;
		dfs(u + 1, s + a[u]._1);
		cnt1 --;
	} 
	if (cnt2 < (n >> 1)) {
		cnt2 ++;
		dfs(u + 1, s + a[u]._2);
		cnt2 --;
	}
	if (cnt3 < (n >> 1)) {
		cnt3 ++;
		dfs(u + 1, s + a[u]._3);
		cnt3 --;
	}
}
void solve() {
	ans = 0;
	cin >> n;
	if (n <= 30) 
		C = 1;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i]._1 >> a[i]._2 >> a[i]._3;
		if (a[i]._3 != 0) 
			A = B = 1;
		if (a[i]._2 != 0) 
			A = 1;
	}
	dfs(1, 0);
	cout << ans << "\n";
}
signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> t;
	while (t --) 
		solve();
	return 0;
}

