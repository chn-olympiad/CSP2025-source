#include <bits/stdc++.h>
using namespace std;

int n,m,k;
long long ans;

struct P{
	int u, v, w;
}b[1000001];
int c[11], a[10001];

inline bool cmp(P x, P y){
	return x.w < y.w;
}

int main(){
	freopen ("road.in", "r", stdin);
	freopen ("road.out", "w", stdout);
	scanf ("%d%d%d", &n, &m, &k);
	for (int i = 1;i <= m; i++)
		scanf ("%d%d%d", &b[i].u, &b[i].v, &b[i].w);
	for (int i = 1;i <= k; i++){
		scanf ("%d", &c[i]);
		for (int j = 1;j <= n; j++)
			scanf ("%d", &a[i]);
	}
	sort (b + 1, b + n + 1,cmp);
	for (int i = 1;i <= m;i++){
		ans += b[i].w;
	}
	printf ("%lld", ans);
}
