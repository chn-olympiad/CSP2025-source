#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
struct edge{
	int u, v, w;
	bool operator < (edge b){
		return w < b.w;
	}
};
vector<edge> e;
int n, m, k, ans = 0;
bool vis[N];
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d %d %d", &n, &m, &k);
	for(int i = 1; i <= m; i++){
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		e.push_back({u, v, w});
	}
	sort(e.begin(), e.end());
	int cnt = 0;
	for(int i = 0; i < e.size(); i++){
		int u = e[i].u, v = e[i].v;
		if(!vis[u] || !vis[v]){
			vis[u] = vis[v] = 1;
			ans += e[i].w;
			cnt++;
		}
		if(cnt >= n - 1) break;
	}
	cout << ans;
	return 0;
}
