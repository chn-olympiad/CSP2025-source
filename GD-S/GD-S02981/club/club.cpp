#include <bits/stdc++.h> 
using namespace std;

int n, ans = 0;
struct node{
	int a, b, c, mx, mn, md, mxid, mnid, mdid;
	bool operator < (const node &A) const {
		if (mx - md == A.mx - A.md) return md - mn > A.md - A.mn;
		return mx - md > A.mx - A.md;
	}
} a[100005];
struct node2{
	int val, id;
	bool operator < (const node2 &A) const {
		return val < A.val;
	}
};
void solve() {
	scanf("%d", &n);
	ans = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d%d%d", &a[i].a, &a[i].b, &a[i].c);
		node2 tmp[3] = {{a[i].a, 0}, {a[i].b, 1}, {a[i].c, 2}};
		sort(tmp, tmp + 3);
		a[i].mx = tmp[2].val;
		a[i].md = tmp[1].val;
		a[i].mn = tmp[0].val;
		a[i].mxid = tmp[2].id;
		a[i].mdid = tmp[1].id;
		a[i].mnid = tmp[0].id;
	}
	sort(a + 1, a + n + 1);
	int c[3] = {0, 0, 0};
	for (int i = 1; i <= n; i++) {
		if (c[a[i].mxid] < n / 2) {
			c[a[i].mxid]++;
			ans += a[i].mx;
		} else if (c[a[i].mdid] < n / 2) {
			c[a[i].mdid]++;
			ans += a[i].md;
		} else {
			c[a[i].mnid]++;
			ans += a[i].mn;
		}
	}
	printf("%d\n", ans);
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	scanf("%d", &T);
	while (T--) solve();
	return 0;
}
