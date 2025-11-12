#include <bits/stdc++.h>
using namespace std;
int n, m, k, c[15], a[15][10005], f[10005], cnt;
long long ans;
bool A;
struct node{
	int u, v, w;
	bool operator < (const node &x)const{
		return w < x.w;
	}
}e[1000005];
int find(int x){
	while(x != f[x])x = f[x] = f[f[x]];
	return x;
}
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1; i <= n; i++)f[i] = i;
	for(int i = 1; i <= m; i++){
		scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
	}
	if(k)A = 1;
	for(int i = 1; i <= k; i++){
		scanf("%d", c + i);
		if(c[i])A = 0;
		for(int j = 1; j <= n; j++){
			scanf("%d", &a[i][j]);
			if(a[i][j])A = 0;
		}
	}
	if(A){
		printf("0");
		return 0;
	}
	sort(e + 1, e + m + 1);
	for(int i = 1; i <= m; i++){
		int u = e[i].u, v = e[i].v, w = e[i].w;
		if(find(u) != find(v)){
			f[find(u)] = find(v);
			cnt++;
			ans += w;
		}
		if(cnt == n - 1)break;
	}
	printf("%lld\n", ans);
	return 0;
}
