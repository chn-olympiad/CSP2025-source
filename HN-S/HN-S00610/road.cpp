#include <bits/stdc++.h>
using namespace std;
struct node {
	int x, y, w;
}e[1000005], b[10005];
long long res, ans;
int n, m, k, cnt, c[10], a[10][10005], fa[20005], siz[20005];
int find(int x) {
	if(fa[x] == x)
		return x;
	return fa[x] = find(fa[x]);
}
void merge(int x, int y) {
	if(siz[x] > siz[y])
		swap(x, y);
	siz[fa[x] = y] += siz[x];
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	for(int i = 1; i <= n; i++)
		siz[fa[i] = i] = 1;
	for(int i = 1; i <= m; i++)
		cin >> e[i].x >> e[i].y >> e[i].w;
	sort(e + 1, e + m + 1, [&](node x, node y) {return x.w < y.w;});
	for(int i = 1; i <= m; i++) {
		int x = find(e[i].x), y = find(e[i].y);
		if(x ^ y)
			b[++cnt] = e[i], ans += e[i].w, merge(x, y);
	}
	for(int i = 0; i < k; i++) {
		cin >> c[i];
		for(int j = 1; j <= n; j++)
			cin >> a[i][j];
	}
	for(int s = 0; s < (1 << k); s++) {
		res = 0;
		for(int i = 0; i < k; i++)
			if(s >> i & 1)
				res += c[i];
		vector<node> e;
		if(res >= ans)
			goto f;
		for(int i = 1; i <= n + k; i++)
			siz[fa[i] = i] = 1;
		for(int i = 1; i <= cnt; i++)
			e.push_back(b[i]);
		for(int i = 0; i < k; i++)
			if(s >> i & 1)
				for(int j = 1; j <= n; j++)
					e.push_back({n + i + 1, j, a[i][j]});
		sort(e.begin(), e.end(), [&](node x, node y) {return x.w < y.w;});
		for(auto i : e) {
			int x = find(i.x), y = find(i.y);
			if(x ^ y) {
				res += i.w, merge(x, y);
				if(res >= ans)
					goto f;
			}
		}
		ans = res;
		f:;
	}
	cout << ans;
	return 0;
}