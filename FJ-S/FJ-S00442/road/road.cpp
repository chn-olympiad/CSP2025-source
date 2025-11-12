#include<bits/stdc++.h>

using namespace std;

int n, m, k, d[10010], c[15], a[15][10010], sum;
struct Node{
	int u, v, w;
}vv;
bool operator<(Node x, Node y){
	return x.w > y.w; 
}
priority_queue<Node> V;


int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= m; i++){
		scanf("%d%d%d", &vv.v, &vv.u, &vv.w);
		V.push(vv);
	}
	for (int i = 1; i <= k; i++){
		scanf("%d", c[i]);
		for (int j = 1; j <= n; j++)
			scanf("%d", &a[i][j]);
	}
	int s = V.size();
	for (int i = 0; i < s; i++){
		int uu = V.top().u, vvv = V.top().v;
		if (!d[uu] || !d[vvv]){
			d[uu] = 1;
			d[vvv] = 1; 
			sum += V.top().w;
		}
		V.pop();
	} 
	if (k == 0){
		printf("%d", sum);
		return 0;
	}
	
}
