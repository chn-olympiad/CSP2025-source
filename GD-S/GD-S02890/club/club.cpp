#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 5;
struct node {
	int id, v;
};
bool cmp(node s1, node s2) {
	return s1.v > s2.v;
}
int t, n;
int a[MAXN][4];
node b[MAXN], c[MAXN], d[MAXN], b1[MAXN], c1[MAXN], d1[MAXN];
set<int> st;
int main() {
	
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	
	while(t--) {
		cin >> n;
		
		for (int i = 1; i <= n; i++) {
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			b[i].v = a[i][1];
			c[i].v = a[i][2];
			d[i].v = a[i][3];
			b[i].id = i;
			c[i].id = i;
			d[i].id = i;
		}
		
		int m = n % 3 == 0 ? n / 3 : n / 3 + 1;
		
		sort(b + 1, b + n + 1,cmp);
		sort(c + 1, c + n + 1,cmp);
		sort(d + 1, d + n + 1,cmp);
		
		int ans = 0;
		for (int i = 1; i <= m; i++) {
			b1[i].id = i;
			b1[i].v = b[i].v;
			c1[i].id = i;
			c1[i].v = c[i].v;
			d1[i].id = i;
			d1[i].v = d[i].v;
			ans += b1[i].v + c1[i].v + d1[i].v;
		}
		
		int lo = m * 3 - n;
		if (lo == 0) {
			cout << ans << endl;
			continue;
		} else if (lo == 1) {
			ans -= min(b1[m].v, min(c1[m].v, d1[m].v));
		} else {
			ans -= (min(max(b1[m].v, c1[m].v), max(c1[m].v, d1[m].v)) + min(b1[m].v, min(c1[m].v, d1[m].v)));
		}
		
		cout << ans << endl;
	}
	
	return 0;
}
