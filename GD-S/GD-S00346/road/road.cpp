#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e7 + 10;
const int M = 1e4 + 10;
ll n, m, k, minn = 1e18;
struct input {
	ll x, y, z;
	bool operator < (const input & r) const {
		return z < r.z;
	}
}a[N], orgi[N];
ll c[11][M], fa[N];
bool chs[11];
ll ln = 0, lm = 0, res, cnt;
ll find (ll x) {
	return (fa[x] == x) ? x : fa[x] = find (fa[x]);
}
void kruskal () {
	for (int i = 1; i <= lm; ++ i) {
		ll fx = find (a[i].x), fy = find (a[i].y);
		if (fx == fy) continue;
		fa[fx] = fy;
		res += a[i].z;
//		cout << a[i].z << '\n';
		if (++ cnt == ln - 1) {
			break;
		}
	}
}
void dfs (ll o) {
	if (o == k + 1) {
//		for (int i = 1; i <= k; ++ i) cout << chs[i] << ' ';
//		cout << '\n';
		res = cnt = 0;
		for (int i = 1; i <= k; ++ i) {
			if (chs[i]) res += c[i][0];
			if (res >= minn) return;
		}
		for (int i = 1; i <= k; ++ i) {
			if (chs[i]) {
				++ ln;
				for (int j = 1; j <= n; ++ j) {
					a[++ lm].x = ln, a[lm].y = j, a[lm].z = c[i][j];
				}
			}
		}
		for (int i = 1; i <= ln; ++ i) fa[i] = i;		
		sort (a + 1, a + lm + 1);
		kruskal ();
		if (cnt == ln - 1) {
//			cout << res << '\n';
			minn = min (minn, res);	
		} 
		ln = n, lm = m;
		for (int i = 1; i <= n; ++ i) {
			a[i] = orgi[i];
		}
		return;	
	}
	dfs (o + 1);
	if (c[o][0] < minn) {
		chs[o] = 1;
		dfs (o + 1);		
	}
	chs[o] = 0;
}
int main () {
	freopen ("road.in", "r", stdin);
	freopen ("road.out", "w", stdout);
	cin >> n >> m >> k;
	ln = n, lm = m;
	for (int i = 1; i <= m; ++ i) {
		cin >> a[i].x >> a[i].y >> a[i].z;
		orgi[i] = a[i];
	}
	for (int i = 1; i <= k; ++ i)
	for (int j = 0; j <= n; ++ j)
		cin >> c[i][j];
	dfs (1);
	cout << minn << '\n';
	return 0; 
}
