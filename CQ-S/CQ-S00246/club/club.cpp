#include <bits/stdc++.h>

#define int long long

using namespace std;

typedef pair<int, int> PII;

namespace zcq_qwq {
	const int N = 100000 + 5;
	
	struct node {
		int mx, mx2, mxi, mx2i;
	} a[N];
	
	int cnt[5], vis[N];
	
	int t, n;
	
	void solve() {
		cin >> n;
		priority_queue<int, vector<PII> , greater<PII> > pq[5];
		for (int i = 1; i <= n; i++) {
			a[i].mx = a[i].mx2 = a[i].mxi = a[i].mx2i = -1;
			for (int j = 1; j <= 3; j++) {
				int x;
				cin >> x;
				if (a[i].mx < x) {
					a[i].mx2 = a[i].mx;
					a[i].mx2i = a[i].mxi;
					a[i].mx = x;
					a[i].mxi = j;
				} else if (a[i].mx2 < x) {
					a[i].mx2i = j;
					a[i].mx2 = x;
				}
			}
		}
		sort(a + 1, a + n + 1, [](node x, node y) {
			if (x.mx2 != y.mx2) return x.mx2 > y.mx2;
			else return x.mx > y.mx;
		});
		memset(cnt, 0, sizeof cnt);
		memset(vis, 0, sizeof vis);
//		pq[1].push({0, 0});
//		pq[2].push({0, 0});
//		pq[3].push({0, 0});
//		cnt[1] = cnt[2] = cnt[3] = 1; 
		int ans = 0;
		for (int i = 1; i <= n; i++) {
//			if (vis[i]) continue;
			if (cnt[a[i].mxi] == n / 2) {
				int t = pq[a[i].mxi].top().second;
				int v = pq[a[i].mxi].top().first;
				int oth = (a[t].mxi == a[i].mxi ? a[t].mx2i : a[t].mxi);
				int oth2 = (a[t].mxi == a[i].mxi ? a[t].mx2 : a[t].mx);
//				cout << a[t].mx << endl;
				if (v < a[i].mx + oth2) {
					pq[a[i].mxi].pop();
					pq[a[i].mxi].push({a[i].mx, i});
					pq[oth].push({oth2, t});
					cnt[oth]++;
					ans += a[i].mx + oth2;
					ans -= v;
				} else {
					pq[a[i].mx2i].push({a[i].mx2, i}); 
					ans += a[i].mx2;
					cnt[a[i].mx2i]++;
				}
			} else {
				pq[a[i].mxi].push({a[i].mx, i});
				cnt[a[i].mxi]++;
				ans += a[i].mx;
			}
//			vis[i] = true;
		}
		cout << ans << endl;
	}
	
	void main() {
		cin >> t;
		while (t--) {
			solve();
		}
	}
}

signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	zcq_qwq::main(); 
	return 0;
}

/*
只选最大和次大。
最大分成一个组，次大分成一个组。
一个人只被分一次。

*/
