#include <iostream>
#include <algorithm>
using namespace std; 

const int MXK = 10 + 5;
const int MXN = 1e4 + MXK + 5;
const int MXM = 1e6 + MXN * MXK + 5; 
struct Edge{int u, v, w;} edge[MXM];
int n, m, k, ecnt, mcnt, fa[MXN];
long long ans;

int find(int x){return fa[x] ? fa[x] = find(fa[x]) : x;} 
inline bool merge(int x, int y){
	x = find(x), y = find(y);
	if (x != y) fa[x] = y;
	return x != y;
}

int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> m >> k;
	for (ecnt = 1; ecnt <= m; ecnt += 1)
		cin >> edge[ecnt].u >> edge[ecnt].v >> edge[ecnt].w;
	for (int j = 1, a; j <= k; j += 1){
		cin >> a;
		for (int i = 1; i <= n; i += 1){
			cin >> a;
			edge[ecnt++] = {i, n + j, a};
		}
	}
	
	sort(edge + 1, edge + ecnt, 
	[](const Edge& lft, const Edge& rgt){
		return lft.w < rgt.w;
	});
	for (int i = 1; i < ecnt; i += 1){
		#define now edge[i]
		if (merge(now.u, now.v)){
			mcnt += 1;
			ans += now.w;
			if (mcnt == n + k - 1) break;
		}
		#undef now
	}
	
	cout << ans << '\n';
	return 0;
}
