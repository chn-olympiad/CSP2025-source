#include <bits/stdc++.h> 
using namespace std;

const int Max = 1e6+5;

int n, m, k, ans; 
map <int,bool> is_lt; //i节点是否被连通 

struct Node {
	int wel;
	int u, v;
}nodes[Max];

bool cmp(Node x, Node y) {
	return x.wel < y.wel;
}

int main() {
	
	ios::sync_with_stdio(false);cin.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);

	cin >> n >> m >> k;
	for (int i=1;i<=m;i++) {
		int u, v;
		cin >> u >> v;
		cin >> nodes[i].wel;
		nodes[i].u = u;
		nodes[i].v = v;
	}

	sort(nodes+1,nodes+m+1,cmp);
	int num_lt = 0;
	
	for (int i=1;i<=m;i++) {
		if (num_lt==n) break;
		int u = nodes[i].u, v = nodes[i].v;
		ans += nodes[i].wel;
		if (!is_lt[u]) num_lt++;
		if (!is_lt[v]) num_lt++;
		is_lt[u] = 1;
		is_lt[v] = 1;
	}
	
	cout << ans;
	
	return 0;
	
} 
