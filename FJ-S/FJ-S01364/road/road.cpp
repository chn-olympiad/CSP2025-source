#include<bits/stdc++.h>
using namespace std;

int n = 0, m = 0, k = 0;
struct EDGE{
	int From;
	int to;
	int val;
};
EDGE edg[200010];
int rn = 0;
int st[10010];
int fa[10010] = {};

int Find(int x) {
	if (fa[x]) {
		return fa[x] = Find(fa[x]);
	} else {
		return x;
	}
}

bool cmp(EDGE A, EDGE B) {
	return A.val < B.val;
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		rn++;
		scanf("%d%d%d", &edg[rn].From, &edg[rn].to, &edg[rn].val);
		rn++;
		edg[rn].From = edg[rn - 1].to;
		edg[rn].to = edg[rn - 1].From;
		edg[rn].val = edg[rn - 1].val;
	}
	int c, cs[10010];
	for (int i = 1; i <= k; i++) {
		cin >> c;
		for (int j = 1; j <= n; j++) {
			cin >> cs[j];
		}
	}
	sort(edg + 1, edg + rn + 1, cmp);
	int tt = 1;
	int ans = 0;
	while (tt <= rn) {
		int t1 = Find(edg[tt].to);
		int t2 = Find(edg[tt].From);
		if (t1 != t2) {
			fa[t1] = Find(t2);
			ans += edg[tt].val;
		}
		tt++;
	}
	cout << ans;
	return 0;
}
