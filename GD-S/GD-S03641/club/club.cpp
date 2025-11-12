#include <bits/stdc++.h>
using namespace std;
const int N =  1e5+10;
bool vis[N];
struct node {
	int id, v, tm;
}x1[N], x2[N], x3[N];
int n;
bool cmp(const node& x, const node& y) {
	return x.v > y.v;
}
void f() {
	int sum = 0, j1 = 1, j2 = 1, j3 = 1, cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt = 0;
	
	while (cnt < n) {
		node d[5];
		d[1].id = x1[j1].id, d[1].tm = 1, d[1].v = x1[j1].v;
		d[2].id = x2[j2].id, d[2].tm = 2, d[2].v = x2[j2].v;
		d[3].id = x3[j3].id, d[3].tm = 3, d[3].v = x3[j3].v;
		sort(d+1, d+4, cmp);
		if (d[1].tm == 1) {
			j1++;
			if (!vis[d[1].id] && cnt1 < n / 2) {
				cnt1++;
				cnt++;
				sum += d[1].v;
			}
			vis[d[1].id] = 1;
		}
		if (d[1].tm == 2) {
			j2++;
			if (!vis[d[1].id] && cnt2 < n / 2) {
				cnt2++;
				cnt++;
				sum += d[1].v;
			}
			vis[d[1].id] = 1;
		}
		if (d[1].tm == 3) {
			j3++;
			if (!vis[d[1].id] && cnt3 < n / 2) {
				cnt3++;
				cnt++;
				sum += d[1].v;
			}
			vis[d[1].id] = 1;
		}
	}
	cout << sum << endl;
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while (t--) {
		memset(vis, 0, sizeof(vis));
		cin >> n;
		for (int i = 1; i <= n; i++) {
			x1[i].id = i, x2[i].id = i, x3[i].id = i;
			cin >> x1[i].v >> x2[i].v >> x3[i].v;
		}
		sort(x1+1, x1+n+1, cmp);
		sort(x2+1, x2+n+1, cmp);
		sort(x3+1, x3+n+1, cmp);
		f();
	}
	return 0;
}
