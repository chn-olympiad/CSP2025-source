#include <bits/stdc++.h>
using namespace std;
const int K = 20;
const int N = 1e5 + 10;
const int M = 1e6 + 10;
int n, m, k;
int c[N], a[K][N];
struct edge{
	int u, v, w;
	bool operator < (const edge &o) const{
		return w < o.w;
	}
	void read(){
		cin >> u >> v >> w;
	}
};
vector <edge> e;

int fa[N + K];
int find(int x){
	while(x != fa[x]) x = fa[x] = fa[fa[x]];
	return x;
} 

void merge(int x, int y){
	int u = find(x), v = find(y);
	if(u == v) return;
	fa[u] = v;
}


bitset <K> f;
int get(){
	vector <edge> t = e;
	int ans = 0, cnt = f.count();
//	cout << cnt << " ";
	for(int i = 1; i <= n + cnt; i ++) fa[i] = i;
	for(int i = 1; i <= k; i ++){
		if(!f[i]) continue;
		ans += c[i];
//		cnt ++;
		for(int j = 1; j <= n; j ++){
			t.push_back((edge){n + i, j, a[i][j]});
		}
	}
	sort(t.begin(), t.end());
	int tot = 0;
	for(int i = 0; i < t.size(); i ++){
		int u = find(t[i].u) , v = find(t[i].v);
		if(u == v) continue;
		tot ++; ans += t[i].w;
//		cout << t[i].u << " " << t[i].v << " " << t[i].w << "%";
		merge(t[i].u, t[i].v);
		if(tot == n + cnt - 1) break;
	}
//	cout << "$" << tot;
	return ans;
}

int res = INT_MAX;
void dfs(int step){
	if(step > k){
		res = min(res, get());
//		cout << res << " ";
//		for(int i = 1; i <= k; i ++) {
//			cout << f[i] << " ";
//		}
//		cout << "\n";
		return;
	}
	f[step] = true;
	dfs(step + 1);
	f[step] = false;
	dfs(step + 1);
}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	e.resize(m + 1);
	for(int i = 0; i < m; i ++){
		e[i].read();
	}
	bool flag = true;
	for(int i = 1; i <= k; i ++){
		cin >> c[i];
		if(c[i]) flag = false;
		for(int j = 1; j <= n; j ++){
			cin >> a[i][j];
			if(a[i][j]) flag = false;
		}
	}
	if(k == 0){
		sort(e.begin(), e.end());
		int cnt = 0, ans = 0;
		for(int i = 1; i <= n; i ++) fa[i] = i;
		for(int i = 0; i < m; i ++){
			int u = find(e[i].u), v = find(e[i].v);
			if(u == v) continue;
			merge(e[i].u, e[i].v);
			ans += e[i].w;
			cnt ++;
			if(cnt == n - 1) break;
		}
		cout << ans;
	}
	else if(flag){
		for(int i = 1; i <= n + k; i ++) fa[i] = i;
		for(int i = 1; i <= k; i ++){
			for(int j = 1; j <= n; j ++){
				merge(n + i, j);
			}
		}
		sort(e.begin(), e.end());
		int ans = 0, cnt = 0;
		for(int i = 0; i < e.size(); i ++){
			int u = find(e[i].u), v = find(e[i].v);
			if(u == v) continue;
			ans += e[i].w; cnt ++;
			merge(e[i].u, e[i].v);
			if(cnt == n + k - 1) break;
		}
		cout << ans;
	}
	else{
		dfs(1);
		cout << res;
	}
	return 0;
} 
/*
4 4 2 
1 4 6 
2 3 7 
4 2 5 
4 3 4 
1 1 8 2 4 
100 1 3 2 4 
*/
