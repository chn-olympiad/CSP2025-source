#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1e4 + 15, MAXM = 1e6 + 5, MAXK = 12;
struct node{
	int u, v, k, flg;
	bool operator < (const node &o) const{
		return k < o.k;
	}
}edge[MAXM], Ed[MAXN * MAXK];
int fa[MAXN], siz[MAXN], c[MAXN];
bool flg[MAXM];
inline void init(int x){
	for(int i = 1; i <= x; i++){
		fa[i] = i;
		siz[i] = 1;
	}
}
int find(int v){ return (fa[v] == v) ? v : (fa[v] = find(fa[v])); }
inline bool unite(int x, int y){
	int fx = find(x), fy = find(y);
	if(fx == fy) return false;
	if(siz[fx] > siz[fy]) swap(fx, fy);
	fa[fx] = fy;
	siz[fy] += siz[fx];
	return true;
}
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++){
		int u, v, k;
		cin >> u >> v >> k;
		edge[i].u = u, edge[i].v = v, edge[i].k = k, edge[i].flg = -1;
	}
	int idx = 0;
	for(int i = 1; i <= k; i++){
		cin >> c[i];
		for(int j = 1; j <= n; j++){
			int num;
			cin >> num;
			Ed[++idx] = {n + i, j, num, i - 1};
		}
	}
	sort(edge + 1, edge + m + 1);
	init(n);
	ll ans = 0;
	int cnt = 0;
	for(int i = 1; i <= m; i++){
		if(unite(edge[i].u, edge[i].v)){
			ans += edge[i].k;
			cnt++;
			flg[i] = true;
			if(cnt == n - 1) break;
		}
	}
	for(int i = 1; i <= m; i++)
		if(flg[i]) Ed[++idx] = edge[i];
	sort(Ed + 1, Ed + idx + 1);
	for(int i = 1; i < (1 << k); i++){
		int d = 0;
		ll tot = 0;
		for(int j = 0; j < k; j++){
			if((i >> j) & 1){
				tot += c[j + 1];
				d++;
			}
		}
		init(n + k);
		int cnt = 0;
		for(int j = 1; j <= idx; j++){
			if(Ed[j].flg == -1 || ((i >> Ed[j].flg) & 1)){
				if(unite(Ed[j].u, Ed[j].v)){
					cnt++;
					tot += Ed[j].k;
					if(cnt == n + d - 1) break;
				}
			}
		}
		ans = min(ans, tot);
	}
	cout << ans;
	return 0;
}
