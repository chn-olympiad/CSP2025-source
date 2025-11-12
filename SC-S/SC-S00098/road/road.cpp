#include <iostream>
#include <algorithm>

using namespace std;

const int M = 1e6 + 10, N = 1e4 + 10;

int n, m, k, tot, u[M + N * 10], v[M + N * 10], w[M + N * 10], ind[M + N * 10], c[10], ci[10][N], fa[N];
long long res;

bool compare(int num1, int num2){
	return w[num1] < w[num2];
}

int find(int pos){
	if(fa[pos] != pos) fa[pos] = find(fa[pos]);
	return fa[pos]; 
}

void merge(int pos1, int pos2){
	fa[find(pos1)] = fa[find(pos2)];
}

void init(){
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1; i <= m; i++) scanf("%d%d%d", u + i, v + i, w + i);
	tot = m;
	for(int i = 0; i < k; i++){
		scanf("%d", c + i);
		int min_val = 1e9 + 10, k;
		for(int j = 1; j <= n; j++){
			scanf("%d", ci[i] + j);
			if(ci[i][j] < min_val) k = j, min_val = ci[i][j];
		} 
		res += min_val + c[i];
		for(int j = 1; j <= n; j++){
			if(j == k) continue;
			++tot;
			u[tot] = j, v[tot] = k, w[tot] = ci[i][j];
		}
	}
	for(int i = 1; i <= tot; i++) ind[i] = i;
	sort(ind + 1, ind + tot + 1, compare);
	for(int i = 1; i <= n; i++) fa[i] = i;
}

int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	init();
	for(int i = 1; i <= tot; i++){
		if(find(u[ind[i]]) != find(v[ind[i]])){
			res += w[ind[i]];
			merge(u[ind[i]], v[ind[i]]);
		}
	}
	printf("%lld", res);
	fclose(stdin);
	fclose(stdout);
	return 0;
}