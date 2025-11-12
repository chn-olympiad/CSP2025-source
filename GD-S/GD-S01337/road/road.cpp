#include<bits/stdc++.h>
using namespace std;
struct Edge {
	int u, v; long long c; bool flag;
	bool operator<(const Edge &o) const {
		if(c == o.c) {
			if(flag || o.flag) return u < o.u;
			else return u > o.u; 
		} 
		return c > o.c;
	}
}; vector<Edge> edge;
int fa[10010];
void init(int n) {
	for(int i = 1; i <= n; i++) fa[i] = i;
	return;
}
int find(int x) {
	if(fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}
void merge(int l, int r) {
	l = find(l), r = find(r);
	fa[l] = r;
}
struct Node {
	int v; long long c;
}; vector<Node> G[10010];
priority_queue<Edge> pq;
int c[20][10010];
int getT(int n, int k) {
	long long cnt = 0;
//	sort(edge.begin(), edge.end(), [](Edge l, Edge r) {
//		if(l.c == r.c) return l.u > r. u;
//		return l.c < r.c;
//	});
	for(Edge e: edge) pq.push(e);
	for(int i = 1; i < n + k; i++) {
		while(1){
			Edge e = pq.top(); pq.pop();
			int u = e.u, v = e.v, w = e.c;
	//		printf("%d %d %d \n",u, v, w);
			if(find(u) != find(v)) {
				if(v > n) swap(u, v);
				if(u > n)
					for(int j = 1; j <= n; j++)
						pq.push({u, j, c[u - n][j], 0});
//				printf("%d %d %d\n", u, v, w);
				merge(u, v); 
				G[u].push_back({v, w});
				G[v].push_back({u, w});
				cnt += w;
				break;
			}
		}
	}
	return cnt;
}
//int fa[10010][20];
//void dfs(int u, int fa) {
//	for(int v : G[u]) {
//		
//	}
//}
//int lca(int x, int y) {
//	
//}
//vector<node> G[10010];
int main(){
	freopen("road2.in", "r", stdin);
	freopen("road2.out", "w", stdout);
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	for(int i = 1; i <= m; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, & w);
		edge.push_back({u, v, w, 0});
	}
	for(int i = 1; i <= k; i++) {
		scanf("%d", &c[i][0]);
		for(int j = 1; j <= n; j++) {
			scanf("%d", &c[i][j]);
			edge.push_back({n + i, j, c[i][j] + c[i][0], 1});
		}
	}
	init(n + k);
	int cnt = getT(n, k);
	for(int i = n + 1; i <= n + k; i++)
		if(G[i].size() == 1)
			cnt -= G[i][0].c;
	cout << cnt;
	return 0;
}

