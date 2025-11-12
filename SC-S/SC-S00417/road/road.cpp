#include <bits/stdc++.h>
#define LL long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
const LL INF = 1e18;
const int maxn = 2e5;
const int maxm = 1e6+5;
int n, m, k, c[12], a[12][maxn];
int fa[maxn], head[12], tail[12], num, tot;
LL ans, Min = INF;
struct Edge {
	int x, y, z;
} E[maxm], e[12][maxn];
int operator <(Edge A, Edge B) {
	return A.z < B.z;
}
int find(int A) {
	if (fa[A] != A) fa[A] = find(fa[A]);
	return fa[A];
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++)
		cin >> E[i].x >> E[i].y >> E[i].z;
	sort(E + 1, E + 1 + m);
	for (int i = 1; i <= n; i++)
		fa[i] = i;
	for (int i = 1; i <= m; i++) {
		int tx = find(E[i].x), ty = find(E[i].y);
		if (tx == ty) continue;
		fa[ty] = tx;
		e[0][++tail[0]] = E[i];
	}
	for (int i = 1; i <= k; i++) {
		cin >> c[i];
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
			e[i][++tail[i]] = (Edge) {
				n + i, j, a[i][j]
			};
		}
		sort(e[i] + 1, e[i] + 1 + n);
	}
	for (int s = 0; s < (1 << k); s++) {
		priority_queue<pair<int, int > > q;
		q.push(mp(-e[0][1].z, 0));
		head[0] = 1;
		ans = num = 0, tot = n;
		for (int i = 1; i <= k; i++) {
			if (!(s & (1 << (i - 1)))) continue;
			ans += c[i];
			tot++;
			q.push(mp(-e[i][1].z, i));
			head[i] = 1;
		}
		for (int i = 1; i <= n + k; i++)
			fa[i] = i;
		while (!q.empty()) {
			int u = q.top().se;
			int d = -q.top().fi;
			q.pop();
			int tx = find(e[u][head[u]].x), ty = find(e[u][head[u]].y);
			if (tx != ty) {
				fa[ty] = tx;
				ans += d;
				num++;
			}
			if (num == tot - 1) break;
			head[u]++;
			if (head[u] <= tail[u])
				q.push(mp(-e[u][head[u]].z, u));
		}
		Min = min(Min, ans);
	}
	cout << Min << '\n';
	return 0;
}