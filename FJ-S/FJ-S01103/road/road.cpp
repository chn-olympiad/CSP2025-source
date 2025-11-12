#include<bits/stdc++.h>
using namespace std;
const int N = 1e4+20;
int n, m, k, f[N], ans, cnt, c[15];
bool flag;
int find(int x){
	if(f[x] == x) return x;
	return f[x] = find(f[x]);
}
struct node{
	int u, v, w;
}a[N];
bool cmp(node x, node y){
	return x.w < y.w;
}
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1; i <= n + k; i++) f[i] = i;
	for(int i = 1; i <= m; i++)
		scanf("%d%d%d", &a[i].u, &a[i].v, &a[i].w);
	for(int i = 1; i <= k; i++){
		scanf("%d", &c[i]);
		if(c[i] > 0) flag = true;
		for(int j = 1, d; j <= n; j++){
			scanf("%d", &d);
			m++;
			a[m].u = n + i;
			a[m].v = j;
			a[m].w = c[i] + d;
		}
	}
	sort(a + 1, a + m + 1, cmp);
	for(int i = 1; i <= m; i++){
		int fv = find(a[i].v), fu = find(a[i].u);
		if(fv == fu) continue;
		f[fv] = fu;
		ans += a[i].w;
		int x = max(a[i].v, a[i].u);
		if(x > n && flag){
			if(!c[x - m]) continue;
			for(int j = m + (x - 1) * n + 1; j <= m + x * n; j++)
				a[j].w -= c[x - m];
			sort(a + i + 1, a + n + 1, cmp);
			c[x - m] = 0;
		}
	}
	printf("%d\n", ans);
	return 0;
}
