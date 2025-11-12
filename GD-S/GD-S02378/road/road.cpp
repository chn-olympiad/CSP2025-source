#include <fstream>
#include <cstring>
#include <algorithm>
using namespace std;
ifstream cin("road.in");
ofstream cout("road.out");
struct _{ long long fr, to, val; }rd[3000000];
long long n, m, k, u, v, w, ts, ans = 1e18, val[10], vis[10011];
void add(int id, int x, int y, int z){
	rd[id].fr = x, rd[id].to = y, rd[id].val = z;
}
long long dist(int mode){
	memset(vis, 0, sizeof(vis));
	long long cnt = 0, cost = 0, targ = n - 1, id = -1;
	for(int j=1; j<=k; j++)
		if((mode >> (j - 1)) & 1) targ++;
	while(id++, cnt < targ){
		if(!vis[rd[id].fr] || !vis[rd[id].to]) cost += vis[rd[id].val];
		if(!vis[rd[id].fr]) cnt++, vis[rd[id].fr] = 1;
		if(!vis[rd[id].to]) cnt++, vis[rd[id].to] = 1;
	}
	return cost;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	while(m--){
		cin >> u >> v >> w;
		add(ts++, u, v, w);
		add(ts++, v, u, w);
	}
	for(int i=1; i<=k; i++){
		cin >> val[i];
		for(int j=1; j<=n; j++){
			cin >> w;
			add(ts++, n+i, j, w);
			add(ts++, j, n+i, w);
		}
	}
	sort(rd, rd + ts, [&](_ a, _ b){ return a.val < b.val; });
	for(int i=0; i<(1<<k); i++){
		long long res = 0;
		for(int j=1; j<=k; j++)
			if((i >> (j - 1)) & 1) ts += val[j];
		ans = min(res + dist(i), ans);
	}
	cout << ans;
	return 0;
}
