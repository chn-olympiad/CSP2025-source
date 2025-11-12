#include<bits/stdc++.h>
using namespace std;

int const N = 1E4 + 5, M = 1e6 + 5;
int n, m, k, c[15], a[10][N], mi[15], mi2[15], p[15];

vector<int>rle;

//struct Node {
//	int v, w;
//};
//vector<Node> g[N];

struct Edge {
	int u, v, w;
}edge[M];

bool cmp(Edge a, Edge b) {
	return a.w < b.w;
}

bool vis[N];

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++) {
		cin >> edge[i].u >> edge[i].v >> edge[i].w;
	}
	for(int i = 1; i <= k; i++) {
		cin >> c[i];
		mi[i] = mi2[i] = INT_MAX;
		for(int j = 1; j <= n; j++) {
			int a;
			cin >> a;
			if(a <= mi[i]) mi2[i] = mi[i], mi[i] = a;
			else if(a < mi2[i]) mi2[i] = a;
		}
	}
	
	
	sort(edge + 1, edge + 1 + m, cmp);
	
	int ans = 0;
	for(int i = 1; i <= m; i++) {
		int u = edge[i].u, v = edge[i].v, w = edge[i].w;
		if(vis[u] == true && vis[v] == true) continue;
		vis[u] = vis[v] = true;
		ans += w;
		rle.push_back(i);
	}
//	cout << ans << endl;
	
	for(int i = n - 2; i >= n - 2; i--) {
		int u = edge[rle[i]].u, v = edge[rle[i]].v, w = edge[rle[i]].w;
		int a = w;
		for(int j = 1; j <= k; j++) {
			a = min(a, mi[j] + mi2[j] + c[j]);
		}
		ans = ans - w + a;
	}
	
	cout << ans << endl;
	return 0;
}

