#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int t, ans, hal;
int c[5];
int n;
struct k{
	int s, p, l;
}a[maxn][5];
struct ok{
	int id, mi, ma;
}q[maxn];
bool cmp(ok x, ok y) {
	if(x.mi != y.mi) return x.mi > y.mi;
	return x.ma >= y.ma;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while(t--) {
		memset(c, 0, sizeof(c));
		memset(q, 0, sizeof(q));
		cin >> n;
		ans = 0;
		for(int i = 1; i <= n; i++) {
			int k = 0;
			for(int j = 1; j <= 3; j++) {
				cin >> a[i][j].s;
				if(j == 1) a[i][j].p = 0, k = a[i][j].s;
				else a[i][j].p = a[i][j].s - k;
				a[i][j].l = j;
			}
			if(a[i][3].p < a[i][1].p) swap(a[i][3], a[i][1]);
			if(a[i][3].p < a[i][2].p) swap(a[i][3], a[i][2]);
			if(a[i][2].p < a[i][1].p) swap(a[i][2], a[i][1]);
			q[i].id = i;
			q[i].mi = a[i][3].s - a[i][2].s;
			q[i].ma = a[i][3].s;
		}
		hal = n / 2;
		sort(q + 1, q + n + 1, cmp);
		for(int i = 1; i <= n; i++) {
			int j = q[i].id;
			int num = a[j][3].l;
			if(c[num] == hal) ans += a[j][2].s;
			else ans += a[j][3].s, c[num]++;
		}
		cout << ans << '\n';
	}
	return 0;
}
