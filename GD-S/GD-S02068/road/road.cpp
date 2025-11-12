#include<bits/stdc++.h>
using namespace std;
int n, m, k, v, u, w, maxn, c, a;
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d", &n);
	scanf("%d", &m);
	scanf("%d", &k);
	for (int i = 1; i <= m; i++){
		scanf("%d", &u);
		scanf("%d", &v);
		scanf("%d", &w);
	}
	for (int i = 1; i <= k; i++){
		scanf("%d", &c);
		int sum = c;
		for (int j = 1; j <= n; j++){
			cin >> a;
			sum += a;
		}
		maxn = max(maxn, sum);
	}
	printf("%d", maxn);
	return 0;
}
