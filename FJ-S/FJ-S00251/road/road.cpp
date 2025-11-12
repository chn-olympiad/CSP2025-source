#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxN 10010
struct edge {
	int v, w;
};
int n, m, k;
vector <edge> e[maxN];
void klu () {
	for (int i = 1; i <= n; i++) {
		
	}
}
int main () {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	int u, v, w;
	for (int i = 1; i <= m; i++) {
		cin>>u>>v>>w;
		edge tmp1, tmp2;
		tmp1.v = v, tmp1.w = w, tmp2.v = u, tmp2.w = w;
		e[u].push_back(tmp1), e[v].push_back(tmp2);
	}
	return 0;
}
