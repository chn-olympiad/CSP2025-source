#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n;
struct Node {
	int x, y;
} a[10];
int Cmp(Node x, Node y)
{
	return x.x > y.x;
}
struct node {
	int value, mxid, seid, mx, se;
} b[N];
int cmp(node x, node y) {
	return x.value > y.value;
}
int cnt[10];
void Solve() {
	int mx, se;
	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> a[1].x >> a[2].x >> a[3].x;
		a[1].y = 1;
		a[2].y = 2;
		a[3].y = 3;
		sort (a+1, a+4, Cmp);
		mx = a[1].y, se = a[2].y;
		b[i] = {a[1].x - a[2].x, mx, se, a[1].x, a[2].x};
	}
	sort (b+1, b+n+1, cmp);
	int res = 0;
	cnt[1] = cnt[2] = cnt[3] = 0;
	for (int i=1; i<=n; i++) {
		if (cnt[b[i].mxid] == n/2) {
			res += b[i].se;
			++cnt[b[i].seid];
		} else {
			res += b[i].mx;
			++cnt[b[i].mxid];
		}
	}
	cout << res << '\n';
}
signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
    ios :: sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--)
        Solve();
    return 0;
}
