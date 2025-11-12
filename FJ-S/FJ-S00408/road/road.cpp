#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5, M = 1e6; 
int n, m, k;
struct edge{
	int to, nxt, w;
}e[M << 1];
int head[N], tot;
void add(int u, int v, int w){
	e[++tot].to = v;
	e[tot].nxt = head[u];
	e[tot].w = w;
	head[u] = tot;
}
//最小生成树
bool vis[N];
int ans, cnt;
queue <int> q;
void BFS(){
	q.push(1);
	while(!q.empty()){
	int x = q.front();
	q.pop();
	if(!vis[x]){
		vis[x] = 1;
		for(int i = head[x]; i ; i =e[i].nxt){
			int u = e[i].to;
			int w = e[i].w;
			cnt = min(w, cnt);
			q.push(u);
		}
		ans += cnt;
	}
	}
}
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for(int i = 1 ; i <= m ; i ++){
		int u, v, w;
		cin >> u >> v >> w;
		add(u, v, w);
		add(v, u, w);
	}
	BFS();
	cout << ans << "\n";
	return 0;
}
