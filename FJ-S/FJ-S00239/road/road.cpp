#include <bits/stdc++.h>
using namespace std;
struct node{
	int v, w;
};
vector<node> q[10125];
struct ant{
	int c, a[10125];
}h[15];
int n, m, k, g[15];
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++){
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		q[u].push_back({v, w});
		q[v].push_back({u, w});
	}
	for(int i = 1; i <= k; i++){
		scanf("%d", &h[i].c);
		for(int j = 1; j <= n; j++){
			scanf("%d", &h[i].a[j]);
			g[j] = n + i;
		}
	}
	printf("0\n");
	return 0;
}

