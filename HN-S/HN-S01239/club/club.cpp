#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 5;
int n;
int a[N][4], d[N][3], to[N];
struct node {
	int name, diff;
}c[N];
int cnt;
bool cmp(node x, node y) {
	return x.diff < y.diff;
}
int down(int id, int sum) {
	for (int i = 1; i <= n; i++) {
		if (to[i] == id) {
			c[++cnt] = {i, min(d[i][1], d[i][2])};
		}
	}
	sort(c + 1, c + 1 + cnt, cmp);
	/*
	for (int i = 1; i <= cnt; i++) {
		cout << c[i].name << " " << c[i].diff << "\n";
	}
	*/
	int res = 0;
	for (int i = 1; i <= sum; i++) {
		res += c[i].diff;
	}
	return res;
}
void init() {
	memset(a, 0, sizeof a);
	memset(d, 0, sizeof d);
	cnt = 0;
	return ;
}
void solve() {
	init();
	cin >> n;
	int sum1 = 0, sum2 = 0, sum3 = 0;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i][1] >> a[i][2] >> a[i][3];
		int maxi = max(max(a[i][1], a[i][2]), a[i][3]);
		ans += maxi;
		if (maxi == a[i][1]) {
			to[i] = 1;
			sum1++;
			d[i][1] = abs(a[i][1] - a[i][2]);
			d[i][2] = abs(a[i][1] - a[i][3]);
		} else if (maxi == a[i][2]) {
			to[i] = 2;
			sum2++;
			d[i][1] = abs(a[i][1] - a[i][2]);
			d[i][2] = abs(a[i][2] - a[i][3]);
		} else {
			to[i] = 3;
			sum3++;
			d[i][1] = abs(a[i][3] - a[i][2]);
			d[i][2] = abs(a[i][1] - a[i][3]);
		}
	}
	if (sum1 * 2 > n) {
		cout << ans - down(1, sum1 - (n / 2)) << "\n";
		return ;	
	}
	if (sum2 * 2 > n) {
		cout << ans - down(2, sum2 - (n / 2)) << "\n";
		return ;	
	}
	if (sum3 * 2 > n) {
		cout << ans - down(3, sum3 - (n / 2)) << "\n";
		return ;	
	}
	cout << ans << "\n";
	return ;
}
signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
	return 0;
}
/*
rp++
*/

