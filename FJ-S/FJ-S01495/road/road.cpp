#include <bits/stdc++.h>
#define endl "\n"
#define MAXN 10005
#define MAXM 100005
#define MAXK 15
using namespace std;
struct Edge{
	int u, v, w;// 1 - n : 城市 n + 1 ~ n + k 乡村 
} cur;
int n, m, k, c_price[MAXK], u, v, w, c_dis[MAXK][MAXN], f[MAXN], cnt = 0, ans = 0;
int mincp = 1e9,mincd = 1e9;
bool cmp(const Edge& a,const Edge& b) {
	return a.w > b.w;
}
int find(int x){
	return x == f[x] ? x : f[x] = find(f[x]);
}
inline void merge(int x,int y){
	int fx = find(x);
	int fy = find(y);
	if(fx != fy) f[fx] = fy;
}
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin.tie(0) -> sync_with_stdio(0);
	cin >> n >> m >> k;
	priority_queue<Edge, vector<Edge>, decltype(&cmp)> q(cmp);
	for(int i = 1;i <= n;i++) f[i] = i;
	for (int i = 1;i <= m;i++){
		cin >> u >> v >> w;
		q.push(Edge {u, v, w});
	}
	for (int i = 1;i <= k;i++){
		cin >> c_price[i];
		mincp = min(mincp, c_price[i]);
		for(int j = 1;j <= n;j++){
			cin >> c_dis[i][j];
			mincd = min(mincd, c_dis[i][j]);
		}
	}
	if(mincp == 0 && mincd == 0){
		cout << 0;
		return 0;
	}
	while (!q.empty()){
		cur = q.top();
		q.pop();
		if (find(cur.u) != find(cur.v)) {
			merge(cur.u, cur.v);
			cnt ++;
			ans += cur.w;
			for (int i = 1;i <= k;i++){
				if(c_dis[i][cur.u] + c_dis[i][cur.v] < cur.w){
					c_price[i] -= cur.w - c_dis[i][cur.u] - c_dis[i][cur.v];
				}
			}
		}
		if (cnt == n - 1) break;
	}
	for (int i = 1;i <= k;i++){
		if(c_price[i] < 0) ans += c_price[i];
	}
	cout << ans;
	return 0;
}
