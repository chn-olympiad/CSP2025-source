#include <bits/stdc++.h>
using namespace std;
const int MM = 1e6 + 10, NN = 1e4 + 10;
int n, m, k, len;
#define int long long
struct pts16{ int u, v, w; } e[MM << 1];
bool cmp(const pts16 &a, const pts16 &b)
  { return a.w < b.w; }
int fa[NN + 10];
int Find(int x)
  { return x == fa[x] ? x : fa[x] = Find(fa[x]); }
void join(int x, int y) {
	int fx = Find(x), fy = Find(y);
	fa[fx] = fy;
}
int pts16() {
//	cout << "pts16" << '\n';
	for(int i = 1; i <= m and cin >> e[i].u >> e[i].v >> e[i].w; i ++);
	sort(e + 1, e + 1 + m, cmp);
	for(int i = 1; i <= n; i ++) fa[i] = i;
	int ans = 0ll;
	for(int i = 1; i <= n; i ++) {
		if(Find(e[i].u) != Find(e[i].v))
		  { join(e[i].u, e[i].v); ans += e[i].w; }
	}
	return ans;
}
int ptsA() {
	sort(e + 1, e+ 1 + len, cmp);
	for(int i = 1; i <= n + k; i ++) fa[i] = i;
	int ans = 0ll;
	for(int i = 1; i <= len; i ++) {
		if(Find(e[i].u) != Find(e[i].v))
		  { join(e[i].u, e[i].v); ans += e[i].w; }
	}
	return ans;
}
signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios :: sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	if(k == 0) return cout << pts16(), 0;
	for(int i = 1; i <= m; i ++)
	  cin >> e[i].u >> e[i].v >> e[i].w;
	len = m;
	for(int i = 1, c; i <= k and cin >> c; i ++) {
		for(int j = 1, w; j <= n and cin >> w; j ++) {
			e[++ len] = {n + i, j, w};
		}
	}
	return cout << ptsA(), 0;
}
/*
4 4 0
1 4 6
2 3 7
4 2 5
4 3 4
*/
