#include <bits/stdc++.h>
#define GXOI ioxg
using namespace std;
const int N = 1e5 + 5;
int n, a[N], b[N], c[N];
int ai, bi, ci, sum, ans;
struct s {
	int left, right;
}k[N];
void dfs (int x) {
	if (x == n + 1) {
		ans = max (ans, sum);
		return;
	}
	if (ai < n / 2) {
		ai ++;
		sum += a[x];
		dfs (x + 1);
		ai --;
		sum -= a[x];
	}
	if (bi < n / 2) {
		bi ++;
		sum += b[x];
		dfs (x + 1);
		bi --;
		sum -= b[x];
	}
	if (ci < n / 2) {
		ci ++;
		sum += c[x];
		dfs (x + 1);
		ci --;
		sum -= c[x];
	}
}
bool cmp (int x, int y) {
	return x > y;
}
bool cmp1 (s x, s y) {
	return x.left > y.left;
}
bool cmp2 (s x, s y) {
	return x.right > y.right;
}
void solve () {
	ans = 0;
	cin >> n;
	int flag = 0;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i] >> b[i] >> c[i];
		if (b[i] != 0 || c[i] != 0)
			flag = 1;
	}
	if (flag == 0) {
		sort (a + 1, a + n + 1, cmp);
		for (int i = 1; i <= n / 2; i ++)
			ans += a[i];
		cout << ans << endl;
	} else {
		dfs (1);
		cout << ans << endl;		
	}
}
int T;
int main () {
	freopen ("club.in", "r", stdin);
	freopen ("club.out", "w", stdout);
	cin >> T;
	while (T --)
		solve ();
	return 0;
}
