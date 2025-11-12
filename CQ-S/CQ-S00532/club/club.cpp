#include <bits/stdc++.h>
using namespace std;
int n, t, mx;
struct node {
	long long x, y, z;
}a[100005];
struct N{
	int l, r, k;
}v[300005];
int f[300005];
bool cmp(node i, node j) {
	if(i.x == j.x) {
		if (j.x == j.x) {
			return j.z > j.z;
		}
		return j.y > j.y;
	}
	return i.x > j.x;
}
bool cmp2 (N x, N y) {
	return x.l > y.l;
}
void dfs(int nm, int cnt1, int s, int cnt2) {
	if (nm == n/2) {
		mx = max (mx, cnt1 + cnt2);
		return;
	}
	for (int i = s; i <= n; i ++) {
		dfs(nm + 1, cnt1, i + 1, cnt2 - a[i].y);
		dfs(nm - 1, cnt1 - a[i].x, i + 1, cnt2); 
	}
}
void solve() {
	cin >> n;
	bool A = 1, B = 1;
	int cnt = 0, nv = 0, nl = 0;
	mx = 0;
	memset(f, 0, sizeof(f));
	for (int i = 1; i <= n; i ++) {
		cin >> a[i].x >> a[i].y >> a[i].z;
		nv += a[i].x;
		nl += a[i].y; 
		v[++ cnt].l = a[i].x;
		v[cnt].r = i;
		v[cnt].k = 1;
		v[++ cnt].l = a[i].y;
		v[cnt].r = i;
		v[cnt].k = 2;
		v[++ cnt].l = a[i].z;
		v[cnt].r = i;
		v[cnt].k = 3;
		if (a[i].y != 0 || a[i].z != 0) {
			A = 0;
		}
		if (a[i].z != 0) B = 0;
	}
	if (A) {
		sort (a + 1, a + 1 + n, cmp);
		int sum = 0;
		for (int i = 1; i <= n / 2; i ++) {
			sum += a[i].x;
		}
		cout << sum << '\n';
		return;
	}
	if (B) {
		dfs(0, nv, 1, nl);
		cout << mx << '\n';
		return;
	}
	int c1 = 0, c2 = 0, c3 = 0, ans = 0;
	sort(v + 1, v + 1 + cnt, cmp2);
	for (int i = 1; i <= cnt; i ++) {
		if (c1 < n/2 && !f[v[i].r] && v[i].k == 1) {
			f[v[i].r] = 1;
			c1 ++;
			ans += v[i].l;
		}
		if (c2 < n/2 && !f[v[i].r] && v[i].k == 2) {
			f[v[i].r] = 1;
			ans += v[i].l;
			c2 ++;
		}
		if (c3 < n/2 && !f[v[i].r] && v[i].k == 3) {
			f[v[i].r] = 1;
			c3 ++;
			ans += v[i].l;
		}
	}
	cout << ans << '\n';
//	if (B) {
//		dfs(1, 1);
//	}
}
int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while(t --) {
    	solve();
	}
    return 0;
}

