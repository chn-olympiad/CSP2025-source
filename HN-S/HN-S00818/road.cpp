/*
csp-s 2025 rp ++
*/
#include<bits/stdc++.h>
#define N 10005
#define M 1000005
#define K 15
using namespace std;
struct Node{
	int u, v, w;
}a[M], b[K][N];
int n, m, k, c[K], f[N + K], tot, tota;
long long Ans, ans;
__inline__ bool cmp(Node x, Node y){
	return x.w < y.w;
}
__inline__ int find(int x){
	return f[x] == x ? x : f[x] = find(f[x]);
}
__inline__ void hb(int u, int v){
	f[find(u)] = find(v);
}
void work(int x){
	if(x != 1 && a[x / 2].w > a[x].w){
		swap(a[x / 2], a[x]);
		work(x / 2);
	}
}
void work1(int x){
	if(x * 2 + 1 <= tota && a[x * 2 + 1].w < a[x].w && a[x * 2 + 1].w < a[x * 2].w){
		swap(a[x * 2 + 1], a[x]);
		work1(x * 2 + 1);
	}
	else if(x * 2 <= tota && a[x * 2].w < a[x].w){
		swap(a[x * 2], a[x]);
		work1(x * 2);
	}
}
bool vis[K];
__inline__ void work(){
	for(int i = 1; i <= n + k; i ++){
		f[i] = i;
	}
	int idx = n - 2;
	tota = 0;
	Ans = 0;
	vector<int>qwq;
	qwq.clear();
	for(int i = 0; i <= k; i ++){
		if(vis[i]){
			qwq.push_back(i);
			idx ++;
			Ans += c[i];
			tota += n - (i == 0);
		}
	}
	int ttot[15];
	for(int i = 0; i <= k; i ++){
		ttot[i] = 1;
	}
	for(int i = 1; i <= tota && idx; i ++){
		int id = 0, w = 1e9;
		for(int j : qwq){
			if(vis[j] && ttot[j] <= n - (j == 0)){
				if(b[j][ttot[j]].w < w){
					id = j;
					w = b[j][ttot[j]].w;
				}
			}
		}
		a[i] = b[id][ttot[id]];
		ttot[id] ++;
		if(find(a[i].u) != find(a[i].v)){
			idx --;
			Ans += a[i].w;
			if(Ans >= ans){
				return;
			}
			hb(a[i].u, a[i].v);
		}
	}
	ans = min(Ans, ans);
}
void dfs(int x){
	if(x > k){
		work();
		return;
	}
	dfs(x + 1);
	vis[x] = 1;
	dfs(x + 1);
	vis[x] = 0;
}
signed main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i ++){
		cin >> a[i].u >> a[i].v >> a[i].w;
		++ tota;
		work(tota);
	}
	for(int i = 1; i <= k; i ++){
		cin >> c[i];
		for(int j = 1; j <= n; j ++){
			cin >> b[i][j].w;
			b[i][j].u = n + i;
			b[i][j].v = j;
		}
	}
	for(int i = 1; i <= n; i ++){
		f[i] = i;
	}
	int idx = n - 1;
	while(tota && idx){
		if(find(a[1].u) != find(a[1].v)){
			idx --;
			Ans += a[1].w;
			hb(a[1].u, a[1].v);
			b[0][++ tot] = a[1];
		}
		swap(a[1], a[tota]);
		tota --;
		work1(1);
	}
	ans = Ans;
	vis[0] = 1;
	for(int i = 1; i <= k; i ++){
		sort(b[i] + 1, b[i] + n + 1, cmp);
	}
	dfs(1);
	cout << ans;
	return 0;
}
