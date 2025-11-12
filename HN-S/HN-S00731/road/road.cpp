#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 15;
int n, m, k, c[N], d[15][N], fire[15];
bool tf = 1, vis[N];
struct node{
	int cost, v /*, num, lst*/;
	node(int cc, int vv/*, int nn, int ll*/): cost(cc), v(vv)/*, num(nn), lst(ll)*/ {};
	bool operator < (const node &s1) const {
		return s1.cost < cost;
	} 
};
priority_queue<node>q;
vector<node>e[N];
void lcx(){
	int ans = 0;
	q.push(node(0, 1));
	while(!q.empty()){
		node tmp = q.top();
		q.pop();
		int cost = tmp.cost, u = tmp.v;
		if(vis[u])continue;
		vis[u] = 1;
		ans += cost;
//		cout << cost << " " << u << "\n";
		for(auto &i : e[u]){
			node cyw = i;
			if(vis[cyw.v]){
				continue;
			}
			q.push(node(cyw.cost, cyw.v));
		}
	}
	cout << ans << "\n";
}
//void GBQandYFH(){
//	int num = 0;
//	q.push(node(0, 1, 1, 0));
//	while(!q.empty()){
//		node tmp = q.top();
//		q.pop();
//		int cost = tmp.cost, u = tmp.v;
//		if(vis[u] && u <= n)continue;
//		vis[u] = 1;
//		cout << cost << " " << u << " " << num << " " << tmp.num << " " << tmp.lst << "\n";
//		if(tmp.lst > n){
//			d[tmp.lst - n][u] = 0;
//		}
//		if(num == n){
//			cout << cost << "\n";
//			return;
//		}
////		cout << cost << " " << u << "\n";
//		if(u > n){
//			fire[u - n] = 1;
//			d[u - n][tmp.cost] = 0;
//			for(int i = 1; i <= n; i++){
//				if(!vis[i]){
//					q.push(node(cost + d[u - n][i], i, 0));
//				}
//			}
//			continue;
//		}
//		for(auto &i : e[u]){
//			node cyw = i;
//			if(vis[cyw.v]){
//				continue;
//			}
//			q.push(node(cost + cyw.cost, cyw.v, 0));
//		}
//		for(int i = 1; i <= k; i++){
//			if(fire[i]){
//				q.push(node(cost + d[i][u], n + i, u));
//			}else{
//				q.push(node(cost + d[i][u] + c[i], n + i, u));
//			}
//		}
//	}
//}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++){
		int u, v, w;cin >> u >> v >> w;
		e[u].push_back(node(w, v));
		e[v].push_back(node(w, u));
	}
	for(int i = 1; i <= k; i++){
		cin >> c[i];
		if(c[i] != 0)tf = false;
		for(int j = 1; j <= n; j++){
			cin >> d[i][j];
			if(d[i][j] != 0)tf = false;
		}
	}
	if(k == 0){
		lcx();
	}else if(tf){
		cout << 0 << "\n";
	}else{
//		GBQandYFH();
	}
	return 0;
}/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
