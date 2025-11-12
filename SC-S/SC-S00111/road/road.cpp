#include<bits/stdc++.h>
#define ll long long
#define _for(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
const int N = 1e4 + 15, M = 5e6 + 15;
struct edge{
	int u, v, w;
};
bool cmp(edge a, edge b){
	return a.w < b.w;
}
vector<edge> e;
int n, m, k;
int u, v, w;
int c[15], a[15][N];
bool f = true;
int fa[N];
int ans;
int find(int x){
	return (fa[x] == x ? x : fa[x] = find(fa[x]));
}
int main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	_for(i, 1, m) cin >> u >> v >> w, e.push_back({u, v, w});
	_for(i, 1, k){
		cin >> c[i];
		if(c[i]) f = false;
		_for(j, 1, n) cin >> a[i][j], e.push_back({n + i, j, a[i][j]});
	}
	_for(i, 1, n + k) fa[i] = i;
	sort(begin(e), end(e), cmp);
	for(edge i : e){
		int fx = find(i.u), fy = find(i.v);
		if(fx == fy) continue;
		fa[fx] = fa[fy];
		ans += i.w;
	}
	cout << ans;
	return 0;
}