#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e4, M = 1e6 + 5;
int n, m, k, c[15], a[15][N];
struct edge{
	int x, y, w;
	friend bool operator<(edge x, edge y){
		return x.w < y.w;
	}
}e[M << 1];
int f[N];
int find(int x){
	if (f[x] != x){
		f[x] = find(f[x]);
	}
	return f[x];
}
void merge(int x, int y){
	int a = find(x), b = find(y);
	if (a != b){
		f[a] = b;
	}
}
signed main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%lld%lld%lld", &n, &m, &k);
	for (int i = 1; i <= n * 2; i++) f[i] = i;
	for (int i = 1, x, y, w; i <= m; i++){
		scanf("%lld%lld%lld", &e[i].x, &e[i].y, &e[i].w);
	}
	sort(e + 1, e + 1 + m);
	int sum = 0;
	for (int i = 1; i <= m; i++){
		int a = e[i].x, b = e[i].y;
		if (find(a) != find(b)){
			merge(a, b);
			sum += e[i].w;
		}
	}
	bool ff = 1;
	for (int i = 1; i <= k; i++){
		scanf("%lld", &a[i + n][0]);
		if (a[i + n][0] != 0) ff = 0;
		for (int j = 1, x; j <= n; j++){
			scanf("%lld", &a[i + n][j]);
		}
	}
	if (k == 0) printf("%lld", sum);
	else if (ff){
		int idx = m;
		sum = 0;
		for (int i = 1; i <= n; i++) f[i] = i;
		for (int i = 1; i <= k; i++){
			for (int j = 1; j <= n; j++){
				if (a[i + n][j] == 0){
					merge(i + n, j);
				}else e[++idx] = {i + n, j, a[i + n][j]};
			}
		}
		sort(e + 1, e + 1 + idx);
		for (int i = 1; i <= idx; i++){
			int a = e[i].x, b = e[i].y;
			if (find(a) != find(b)){
				merge(a, b);
				sum += e[i].w;
			}
		}
		printf("%lld", sum);
	}
	return 0;
}
