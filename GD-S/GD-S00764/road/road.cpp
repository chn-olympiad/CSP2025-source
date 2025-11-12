#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
const int N = 1e4 + 5, M = 1e6 + 5;
struct edge{
	int v, w;
};
vector<edge> G[N + 20];
int fa[N + 20], cnt, vis[N + 20], c[N + 20], k, n;
void init(int m){
	cnt = m - k;
	for(int i = 1; i <= m; i++){
		fa[i] = i;
	}
}
int find(int &i){
	if(fa[i] == i) return i;
	return find(fa[i]);
}
void merge(int x, int y){
	int _x = find(x);
	int _y = find(y);
	if(_x == _y){
		return ;
	}
	if(fa[_x] <= n && fa[_y] <= n)cnt--;
	if(_y <= _x) fa[_x] = _y;
	else fa[_y] = _x;
}
long long prim(int r){
	memset(vis, 0, sizeof vis);
	int u = r;
	cout << u << " "; 
	vis[u] = 1;
	long long sum = 0;
	while(cnt > 1){
		long long minn = 0x3f3f3f3f;
		int q;
		for(edge ed : G[u]){
			int v = ed.v, w = ed.w;
			if(vis[v]) continue;
			if(w < minn){
				q = v;
				minn = w;
			}
		}
		if(n + 1 <= q && q <= n + k) sum += c[q];
		merge(u, q);
		vis[q] = 1;
		sum += minn;
		u = q;
	}
	return sum;
}
int main(){
	freopen("road3.in", "r", stdin);
	freopen("road3.out", "w", stdout);
	int m, u, v, w;
	cin >> n >> m >> k;
	init(n + k);
	for(int i = 1; i <= m; i++){
		cin >> u >> v >> w;
		G[u].push_back({v, w});
		G[v].push_back({u, w});
	}
	int a;
    for(int i = n + 1; i <= n + k; i++){
    	cin >> c[i];
    	for(int j = 1; j <= n; j++){
    		cin >> a;
    		G[i].push_back({j, a});
    		G[j].push_back({i, a});
		}
	}
	cout << prim(1) << endl;
	/*long long ans = 0x3f3f3f3f;
	for(int i = n + k; i >= n + 1; i--){
		init(n + k);
		long long l = prim(i);
		cout << l << endl;
		if(l < 0) continue;
		ans = min(ans, l);
	}
	cout << ans << endl;*/
	return 0;
}
