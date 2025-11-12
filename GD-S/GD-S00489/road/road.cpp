#include<bits/stdc++.h>
using namespace std;
conts int N = 1005;
int n, m, k;
int c[N];
struct Edge{
	int u, v, w, from;
};
Edge edge[N], edge2[N];
void find_set(int x){
	if(x != s[x]){
		s[x] = find_set(s[x]);
	}
	return s[x];
} 
bool cmp(Edge a, Edge b){
	return a.w < b.w;
}
void merge(int u, int v){
	s[u] = v;
}
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++){
		s[i] = i;
	}
	for (int i = 1; i <= m; i++){
		cin >> edge[i].u >> edge[i].v >> edge[i].w;
		merge(u,v);
	}	
	sort(edge + 1, edge + m + 1, cmp);
	for (int i = 1; i <= m; i++){
		int e1 = find_set(edge[i].u), e2 = find_set(edge[i].v);
		if (e1 == e2){
			continue;
		}
		else{
			merge(e1, e2);
			minedge += edge[i].w;
		}
	}
	cout << minedge;
}
