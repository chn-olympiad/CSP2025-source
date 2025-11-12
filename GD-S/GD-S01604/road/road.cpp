#include <bits/stdc++.h>
using namespace std;
const int N = 10050, M = 1000050;
int n, m, i, j, k, c, x, y, u, v, f[N], z[15];
long long w, ans;
struct S{
	int a, b, c;
	bool operator < (const S &A) const{
		return c < A.c;
	}
} d[M], p[N*10];
int find(int x){
	return f[x] = x==f[x]?x:find(f[x]);
}
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &c);
	for(i=1; i<=m; i++) scanf("%d%d%d", &d[i].a, &d[i].b, &d[i].c);
	sort(d+1, d+m+1);
	for(i=1; i<=n; i++) f[i] = i;
	for(i=1; i<=m; i++){
		x = d[i].a, y = d[i].b;
		if(find(x) != find(y)) f[f[x]] = f[y], d[++u] = d[i];
	}
	for(x=n+1; x<=n+c; x++){
		scanf("%d", z+x-n-1);
		for(y=1; y<=n; y++) scanf("%d", &k), p[++v] = {x, y, k};
	}
	sort(p+1, p+v+1);
	for(ans=1e18, k=0; k<1<<c; k++){
		for(i=1; i<=n+c; i++) f[i] = i;
		for(w=i=0; i<c; i++){
			if(k&1<<i) w += z[i];
		}
		for(i=j=1; i<=u||j<=v; ){
			if(j>v || i<=u && d[i].c<p[j].c){
				x = d[i].a, y = d[i].b;
				if(find(x) != find(y)) f[f[x]] = f[y], w += d[i].c;
				i++;
			}
			else{
				x = p[j].a, y = p[j].b;
				if((k&1<<x-n-1) && find(x) != find(y)) f[f[x]] = f[y], w += p[j].c;
				j++;
			}
		}
		ans = min(w, ans);
	}
	printf("%lld\n", ans);
	return 0;
}
