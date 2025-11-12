//CC
#include<bits/stdc++.h>
using namespace std;
struct edge{
	int u, v, w;
	friend bool operator < (edge A, edge B){
    	return A.w < B.w;
	}
}a[1000005];
vector<edge>g[10005];
int n, m, k, fa[10005];
int find(int x){
	if(fa[x] == x)return x;
	return fa[x] = find(fa[x]); 
}
void merge(int x, int y){
	fa[find(x)] = find(y);
}
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1; i <= n; i++)fa[i] = i;
	for(int i = 1, u, v, w; i <= m; i++){
		scanf("%d%d%d", &a[i].u, &a[i].v, &a[i].w);
	}
	stable_sort(a + 1, a + m + 1);
	int t = n - 1, i = 1, ans = 0;;
	while(t){
		if(find(a[i].u) != find(a[i].v)){
			merge(a[i].u, a[i].v);
			ans += a[i].w;
			t--;
		}
		i++;
	}
	printf("%d", ans);
	return 0;
} 
//F
