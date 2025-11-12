#include<bits/stdc++.h>

using namespace std;

int ans=0, q=0, city[10006]={-1};

struct edge{
	int to, w, next, cnt, bw;
} edges[1000006];

void add_edge(int u, int v, int w){
	edges[q].w = w;
	edges[q].to = v;
	edges[q].next = city[u];
	city[u] = q++;
}

//void add_town(int v, int bw){
//	edges[q].to = v;
//	edges[q].w = w;
//	edges[q].next = town[t];
//	town[t] = q++;
//}

bool sl(){
	return edges[].w < edges[].w;
}

void solve(){
	sort(edges, edges+1000006, sl());
	
}


int n, m, k, c[12][10006];

int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	
	
	for (int i=0; i<m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		add_edge(u, v, w);
		add_edge(v, u, w);
	}
	for (int i=0; i<k; i++) {
		int c1
		;cin >> c1;
		for(int j=0; j<n; j++) cin >> c[i][j];
	}
	
	for (int l=0; l<k; l++){
		for (int i=0; i<n-1; i++){
			for (int j=i; j<n-1; j++) {
				add_edge(j, j+1, c[l][j]+c[l][j+1]);
				add_edge(j+1, j, c[l][j]+c[l][j+1]);
			}
		}
	}
	
	solve(); 
	
	cout >> ans;
	return 0;
}
