#include <bits/stdc++.h>
#define il inline
using namespace std;

#define int long long
const int Maxn = 1e5 + 5;
int n, a[Maxn][4], cnt[4];
struct Node {
	int dif, nowval, lowerval, nowid, lowerid;
	il friend bool operator < (Node a, Node b) {
		return a.dif > b.dif;
	}
};
il void solve() {
	memset(cnt, 0, sizeof(cnt));
	cin >> n;
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= 3; j ++)
			cin >> a[i][j];
	priority_queue<Node> que[4];
	for (int i = 1; i <= n; i ++) {
		int maxval = -1, maxid = -1;
		int secmax = -1, secid = -1;
		int thimax = -1, thiid = -1;
		if (a[i][1] >= a[i][2] && a[i][1] >= a[i][3]) {
			maxval = a[i][1], maxid = 1;
			if (a[i][2] >= a[i][3]) {
				secmax = a[i][2], secid = 2;
				thimax = a[i][3], thiid = 3;
			} else {
				secmax = a[i][3], secid = 3;
				thimax = a[i][2], thiid = 2;
			}
		} else if (a[i][2] >= a[i][1] && a[i][2] >= a[i][3]) {
			maxval = a[i][2], maxid = 2;
			if (a[i][1] >= a[i][3]) {
				secmax = a[i][1], secid = 1;
				thimax = a[i][3], thiid = 3;
			} else {
				secmax = a[i][3], secid = 3;
				thimax = a[i][1], thiid = 1;
			}
		} else if (a[i][3] >= a[i][1] && a[i][3] >= a[i][2]) {
			maxval = a[i][3], maxid = 3;
			if (a[i][1] >= a[i][2]) {
				secmax = a[i][1], secid = 1;
				thimax = a[i][2], thiid = 2;
			} else {
				secmax = a[i][2], secid = 2;
				thimax = a[i][1], thiid = 1;
			}
		}
		if (cnt[maxid] < n / 2) {			
			que[maxid].push({maxval - secmax, maxval, secmax, maxid, secid});
			cnt[maxid] ++;
		} else {
			int difnow = maxval - secmax;
			int difpre = que[maxid].top().dif;
			if (difnow >= difpre) {
				Node u = que[maxid].top();
				que[u.lowerid].push({-1, u.lowerval, -1, u.lowerid, -1});
				que[maxid].pop();
				que[maxid].push({difnow, maxval, secmax, maxid, secid});
				cnt[u.lowerid] ++;
			} else {
				cnt[secid] ++;
				que[secid].push({secmax - thimax, secmax, thimax, secid, thiid});
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= 3; i ++) {
		while (!que[i].empty()) {
			ans += que[i].top().nowval;
			que[i].pop();
		}
	}
	cout << ans << "\n";
}
signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T; cin >> T;
	while (T --) solve();
	fclose(stdin), fclose(stdout);
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

Ren5Jie4Di4Ling5%
*/
