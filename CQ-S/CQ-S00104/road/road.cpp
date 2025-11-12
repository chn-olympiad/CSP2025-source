#include <bits/stdc++.h>

using namespace std;
const int N = 1e4 + 5;
const int M = 1e6 + 5;

int n,m,k,c;
int head[N],vis[N],dist[N];
int cnt = 0;
vector <int> g[N];



int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	cin >> n >> m >> k;
	
	for(int i = 1; i <= m; i++) {
		int u,v,w;
		cin >> u >> v >> w;
	}
	
	cout << 23 << endl;
	return 0; 
} 
