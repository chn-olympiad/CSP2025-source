#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5 + 5;

int n, cnt[5], tot, ans;

struct node {
	int mx, mx2, id, id2;
	bool operator < (const node B) const {
		return mx2 - mx < B.mx2 - B.mx;
	}
} a[N];

priority_queue<node> q[3];

void solve() {
	cin >> n;
	cnt[1] = cnt[2] = cnt[3] = ans = 0;
	while (!q[1].empty()) q[1].pop();
	while (!q[2].empty()) q[2].pop();
	while (!q[3].empty()) q[3].pop();
	for (int i = 1; i <= n; i++) {
		int v1, v2, v3;
		cin >> v1 >> v2 >> v3;	
		a[i].mx = max(v1, max(v2, v3)); 
		int mini = min(v1, min(v2, v3));
		a[i].mx2 = (v1 + v2 + v3) - mini - a[i].mx;
		if (a[i].mx == v1) a[i].id = 1;
		else if (a[i].mx == v2) a[i].id = 2;
		else if (a[i].mx == v3) a[i].id = 3;
		if (a[i].id != 1 && a[i].mx2 == v1) a[i].id2 = 1;
		else if (a[i].id != 2 && a[i].mx2 == v2) a[i].id2 = 2;
		else if (a[i].id != 3 && a[i].mx2 == v3) a[i].id2 = 3;
	}
	for (int i = 1; i <= n; i++) {
		if (cnt[a[i].id] < (n / 2)) {
			q[a[i].id].push(a[i]);
			ans += a[i].mx;
			cnt[a[i].id] ++;
			continue;
		}
		auto del = q[a[i].id].top();
//		cout << "--- " << i << ' ' << del.mx << '\n';
		if (del.mx2 + a[i].mx - del.mx > 0) {
			ans += del.mx2 + a[i].mx - del.mx;
			q[a[i].id].pop();
			q[a[i].id].push(a[i]);
			q[del.id2].push(del);
			cnt[del.id2] ++;
		} else {
			ans += a[i].mx2;
			q[a[i].id2].push(a[i]);
			cnt[a[i].id2] ++;
		}
	}
	cout << ans << '\n';
}

signed main() {
	cin.tie(0) -> sync_with_stdio(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T; cin >> T;
	while (T --) solve();
	return 0;
}
// unsigned long long CSP_S_2025_RP = -1;
