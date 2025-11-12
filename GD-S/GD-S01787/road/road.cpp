#include <bits/stdc++.h>
using namespace std;
const int maxn = 1.1e6 + 7, maxk = 1e3 + 7;
struct Edge{
	int u, v;
	long long w;
	void in(){
		cin >> u >> v >> w;
	}
	bool operator < (const Edge &o) const {
		return w < o.w;
	}
}e[maxn];
int fa[maxn], a[maxk][maxk], c[maxk];
int n, m, k;
void init(int n){
	for(int i = 1; i <= n; i++) fa[i] = i;
}
int find(int x){
	if(fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}
void merge(int u, int v){
	u = find(u), v = find(v);
	if(u == v) return;
	fa[u] = v;
}
long long krus(int n, int m){
	init(n);
	sort(e + 1, e + 1 + m);
	long long ans = 0;
	for(int i = 1; i <= m; i++){
		int u = e[i].u, v = e[i].v;
		long long w = e[i].w;
		if(find(u) != find(v)) {
			merge(u, v);
			ans += w;
		}
	}
	return ans;
}
long long solve(){
	long long ans = 0x3f3f3f3f3f3f3f3f;
	int om = m;
	for(int S = 0; S < (1 << k); S++){
		m = om;
		long long sum = 0;
		for(int i = 1; i <= k; i++){
			if(S & (1 << (i - 1))) {
				sum += c[i];
				for(int j = 1; j <= n; j++){
					e[++m] = {n + i, j, a[i][j]};
				}
			}
		}
		sum += krus(n, m);
		ans = min(ans, sum);
	}
	return ans;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0); 
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout); 
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++){
		e[i].in();
	}
	bool f = 1;
	for(int i = 1; i <= k; i++){
		int w;
		cin >> c[i];
		if(c[i] != 0) f = 0;
		for(int j = 1; j <= n; j++){
			cin >> w;
			a[i][j] = w;
		}
	}
	if(f) {
		for(int i = 1; i <= k; i++){
			for(int j = 1; j <= n; j++){
				e[++m] = {n + i, j, a[i][j]};
			}
		}
		cout << krus(n + k, m) << endl;
	}
	else {
		cout << solve() << endl;
	}
	return 0;
}
