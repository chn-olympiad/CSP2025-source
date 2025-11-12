#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int T, n;
int a[N][3];
struct node {
	int a, b, c, i;
}d[N];
bool cmp (node x, node y) {
	if (x.a == y.a) {
		if (x.b == y.b) {
			if (x.c == y.c) {
				if (a[x.i][x.a]-a[x.i][x.b] == a[y.i][y.a]-a[y.i][y.b]) {
//					if (a[x.i][x.b]-a[x.i][x.c] == a[y.i][y.b]-a[y.i][y.c]) {
//						if (a[x.i][x.a] == a[y.i][y.a]) {
//							if (a[x.i][x.b] == a[y.i][y.b]) {
//								return a[x.i][x.c] > a[y.i][y.c];
//							}
//							return a[x.i][x.b] > a[y.i][y.b];
//						}
//						return a[x.i][x.a] > a[y.i][y.a];
//					}
					return a[x.i][x.b]-a[x.i][x.c] > a[y.i][y.b]-a[y.i][y.c];
				}
				return a[x.i][x.a]-a[x.i][x.b] > a[y.i][y.a]-a[y.i][y.b];
			}
			return x.c < y.c;
		}
		return x.b < y.b;
	}
	return x.a < y.a;
}
bool tp (pair<int, int> a, pair<int, int> b) {
	return a.first > b.first;
}
int main() {
	freopen ("club.in", "r", stdin);
	freopen ("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			int x, y, z;
			cin >> x >> y >> z;
			pair<int, int> tmp[3] = {{x,1},{y,2},{z,3}};
			sort(tmp, tmp + 3, tp);
			a[i][1] = x; a[i][2] = y; a[i][3] = z;
			d[i] = {tmp[0].second, tmp[1].second, tmp[2].second, i};
//			cout << tmp[0].second << tmp[1].second << tmp[2].second << "\n";
		}
		sort (d + 1, d + n + 1, cmp);
//		for (int i = 1; i <= n; i++) {
//			cout << d[i].i << ":" << d[i].a << " " << d[i].b << " " << d[i].c << "\n"; 
//		}
		int cnt[4] = {0, 0, 0, 0};
		int m = n >> 1;
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			int zy = d[i].a;
			if (cnt[zy] == m) zy = d[i].b;
			if (cnt[zy] == m) zy = d[i].c;
			cnt[zy]++;
//			cout << d[i].i << " " << zy << "\n";
			ans += a[d[i].i][zy];
		}
		cout << ans << "\n";
	}
	return 0;
}

