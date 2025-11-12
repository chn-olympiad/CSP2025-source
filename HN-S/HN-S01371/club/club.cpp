#include <bits/stdc++.h> 
#define int long long

using namespace std;

const int N = 1e5 + 5;
int n, vis[N];
struct Node {
	int val1,  val2, val3;
} a[N];
struct Edge {
	int pos, nxt, val, id;
	bool operator < (Edge B) const {
		if (val != B.val) return val > B.val;
		if (pos != B.pos) return pos < B.pos;
		return nxt < B.nxt;
	}
};

void solve() {
	int ans = 0, cnt[4] = {};
	memset(vis, 0, sizeof(vis));
	vector<Edge> vt;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].val1 >> a[i].val2 >> a[i].val3;
		if (a[i].val1 >= a[i].val2 && a[i].val1 >= a[i].val3) {
			ans += a[i].val1;
			cnt[1]++;
			vis[i] = 1;
		}
		else if (a[i].val2 >= a[i].val1 && a[i].val2 >= a[i].val3) {
			ans += a[i].val2;
			cnt[2]++;
			vis[i] = 2;
		}
		else if (a[i].val3 >= a[i].val1 && a[i].val3 >= a[i].val2) {
			ans += a[i].val3;
			cnt[3]++;
			vis[i] = 3;
		}
		vt.push_back({1, 2, a[i].val2 - a[i].val1, i});
		vt.push_back({2, 1, a[i].val1 - a[i].val2, i});
		vt.push_back({1, 3, a[i].val3 - a[i].val1, i});
		vt.push_back({3, 1, a[i].val1 - a[i].val3, i});
		vt.push_back({2, 3, a[i].val3 - a[i].val2, i}); 
		vt.push_back({3, 2, a[i].val2 - a[i].val3, i}); 
	}
	sort(vt.begin(), vt.end());
	for (int i = 0; i < vt.size(); i++) {
		if (vis[vt[i].id] == vt[i].pos) {
			if (cnt[vt[i].pos] > n / 2 || (vt[i].val >= 0 && cnt[vt[i].nxt] < n / 2)) {
				ans += vt[i].val;
				cnt[vt[i].pos]--;
				cnt[vt[i].nxt]++;
				vis[vt[i].id] = vt[i].nxt;
			}
		}
	}
	cout << ans << endl;
}

signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
	return 0;
}
