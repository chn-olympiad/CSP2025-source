#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, m, k, node;
int u[N], v[N], w[N];
int c[15], a[15][N];
long long pdd;
vector<int> t;
bool cmp (int x, int y) {
	return w[x] < w[y];
}
long long ans;

int fa[N], bel[N];
int find (int x) {
	if (x == fa[x]) {
		return x;
	}
	return fa[x] = find (fa[x]);
}

int main() {
	freopen ("road.in", "r", stdin);
	freopen ("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> k; node = n;
	for (int i = 1; i <= m; i++) {
		cin >> u[i] >> v[i] >> w[i];
		t.emplace_back(i); fa[i] = i;
	}
	sort (t.begin(), t.end(), cmp);
	for (int i = 1; i <= k; i++) {
		cin >> c[i]; 
		pdd += c[i];
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}
	if (pdd == 0) {
		for (int i : t) {
			int x = find (u[i]);
			int y = find (v[i]);
			if (x != y) {
				n--;
				fa[x] = y;
				int tmp = w[i];
				for (int j = 1; j <= k; j++) {
					tmp = min (tmp, a[j][v[i]]);
				}
				ans += tmp;
			}
			if (n == 1) break;
		}
		cout << ans << "\n";
	}
	else {
		for (int i : t) {
			int x = find (u[i]);
			int y = find (v[i]);
			if (x != y) {
				node--;
				fa[x] = y;
				ans += w[i];
			}
			if (node == 1) break;
		}
		cout << ans << "\n";
	}
	return 0;
}

