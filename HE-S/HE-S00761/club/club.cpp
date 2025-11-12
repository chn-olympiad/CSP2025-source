#include <bits/stdc++.h>
using namespace std;

#define int long long 
const int N = 1e5 + 10;

int cnt[N];
bool vis[N];
struct node{
	int x, y, z;
}a[N];
struct stu{
	int val, id, op;
}b[N];
inline bool cmp (stu x, stu y) {
	return x.val < y.val;
}
inline void solve() {
	int n;
	cin >> n;
	int ans = 0;
	cnt[1] = cnt[2] = cnt[3] = 0;
	for (int i = 1; i <= n; i++) {
		vis[i] = 0;
		cin >> a[i].x >> a[i].y >> a[i].z;
		int h = max(a[i].x, max(a[i].y, a[i].z));
		if (h == a[i].x) {
			cnt[1]++;
			ans += a[i].x;
		}
		else if (h == a[i].y) {
			cnt[2]++;
			ans += a[i].y;
		}
		else {
			cnt[3]++;
			ans += a[i].z;
		}
	}
	int k = n / 2, tot = 0;
	int op;
	if (cnt[1] > k) {
		for (int i = 1; i <= n; i++) {
			int h = max(a[i].x, max(a[i].y, a[i].z));
			if (h != a[i].x) continue;
			b[++tot].val = h - a[i].y, b[tot].id = i, b[tot].op = 2;
			b[++tot].val = h - a[i].z, b[tot].id = i, b[tot].op = 3;
		}
		op = 1;
	}
	else if (cnt[2] > k) {
		for (int i = 1; i <= n; i++) {
			int h = max(a[i].x, max(a[i].y, a[i].z));
			if (h != a[i].y) continue;
			b[++tot].val = h - a[i].x, b[tot].id = i, b[tot].op = 1;
			b[++tot].val = h - a[i].z, b[tot].id = i, b[tot].op = 3;
		}
		op = 2;
	}
	else if (cnt[3] > k) {
		for (int i = 1; i <= n; i++) {
			int h = max(a[i].x, max(a[i].y, a[i].z));
			if (h != a[i].z) continue;
			b[++tot].val = h - a[i].x, b[tot].id = i, b[tot].op = 1;
			b[++tot].val = h - a[i].y, b[tot].id = i, b[tot].op = 2;
		}
		op = 3;
	}
	sort(b + 1, b + tot + 1, cmp);
	for (int i = 1; i <= tot; i++) {
		int id = b[i].id;
		if (vis[id]) continue;
		vis[id] = 1;
		if (cnt[b[i].op] == k) continue;
		cnt[op]--, cnt[b[i].op]++;
		ans -= b[i].val;
		if (cnt[1] <= k && cnt[2] <= k && cnt[3] <= k) break;
	}
	cout << ans << '\n';
	return ;
}
signed main () {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) solve();
	return 0;
}
