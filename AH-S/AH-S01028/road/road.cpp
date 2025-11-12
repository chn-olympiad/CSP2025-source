#include <bits/stdc++.h>
using namespace std;

struct node{
	int u, v, w;
}tu[1000005];

int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1; i <= m; i ++)
		scanf("%d%d%d", &tu[i].u, &tu[i].v, &tu[i].w);
	while(k --){
		int c;
		scanf("%d", &c);
		for(int i = 1; i <= n; i ++){
			int a;
			scanf("%d", &a);
		}
	}
	int ans = 0;
	for(int i = 1; i <= m; i ++) ans += tu[i].w;
	printf("%d", ans);
	return 0;
}
