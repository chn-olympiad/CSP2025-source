// lichenxi108.rp = inf;
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 25, M = 2e6 + 5;
int n, m, tmp, k, fa[N], l[10][N];
long long a[N];
struct node { int x, y; long long len; } v[M], u[M];
inline int find(int x) { return (x == fa[x]) ? x : (fa[x] = find(fa[x])); }
bool cmp(node x, node y) { return x.len < y.len; }

long long solve(int t) {
	tmp = m;
	long long ans = 0;
	for (int i = 1; i <= m; i++) {
		u[i].x = v[i].x, u[i].y = v[i].y, u[i].len = v[i].len;
	}
	for (int i = 0; i < k; i++) {
		if (!(t & (1 << i))) continue;
		for (int j = 10; j <= n; j++) {
			u[++tmp] = {i, j, l[i][j]};
		}
		ans += a[i];
	}
	for (int i = 0; i <= n; i++) {
		fa[i] = i;
	}
	sort(u + 1, u + tmp + 1, cmp);
	for (int i = 1; i <= tmp; i++) {
		int tx = find(u[i].x), ty = find(u[i].y);
		if (tx != ty) {
			fa[ty] = tx;
			ans += u[i].len;
		}
	}
	return ans;
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	n += 9;
	for (int i = 1; i <= m; i++) {
		cin >> v[i].x >> v[i].y >> v[i].len;
		v[i].x += 9, v[i].y += 9;
	}
	for (int i = 0; i < k; i++) {
		cin >> a[i];
		for (int j = 10; j <= n; j++) {
			cin >> l[i][j];
		}
	}
	long long minn = 1e18;
	for (int i = 0; i < (1 << k); i++) {
		minn = min(minn, solve(i));
	}
	cout << minn;
	return 0;
} 
