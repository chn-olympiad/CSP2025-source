#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1e4 + 100, MAXM = 1.5e6, MAXK = 15;
const ll INF = 0x3f3f3f3f3f3f3f3f;
struct Edge{
	int u, v;
	ll w;
}e[MAXM];
int fa[MAXN], n, m, k;
ll c[MAXN], a[MAXK][MAXN], ans = INF;
bool vis[MAXK];
bool cmp(Edge x, Edge y){
	return x.w < y.w;
}
int _find(int x){
	if (fa[x] == x) return x;
	return fa[x] = _find(fa[x]);
}
void modify(int x, int y){
	int a = _find(x), b = _find(y);
	fa[a] = b;
	return;
}
ll calc(int st){
	ll res = 0;
	for (int i = 1; i <= k; i++){
		if (st >> (i - 1) & 1){
			res += c[i];
		}
	}
	for (int i = 1; i <= n + k; i++){
		fa[i] = i;
	}
	for (int i = 1; i <= m; i++){
		int u = e[i].u, v = e[i].v;
		if (u < v) swap(u, v);
		if (u > n){
			int x = u - n;
			if (!(st >> (x - 1) & 1)){
				continue;
			}
		}
		if (_find(e[i].u) != _find(e[i].v)){
			modify(e[i].u, e[i].v);
			res += e[i].w;
		}
	}
	return res;
}
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++){
		cin >> e[i].u >> e[i].v >> e[i].w;
	}
	for (int i = 1; i <= k; i++){
		cin >> c[i];
		for (int j = 1; j <= n; j++){
			cin >> a[i][j];
		}
	}
	for (int i = 1; i <= k; i++){
		for (int j = 1; j <= n; j++){
			e[++m] = {n + i, j, a[i][j]};
		}
	}
	sort(e + 1, e + m + 1, cmp);
	if (k <= 5){
		for (int i = 0; i < (1 << k); i++){
			ans = min(ans, calc(i));
		}
		cout << ans << endl;
	}
	else{
		cout << calc((1 << k) - 1) << endl;
	}
	return 0;
}