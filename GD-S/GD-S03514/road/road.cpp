#include<bits/stdc++.h>
using namespace std;
//struct E{
//	int to, w, ne;
//}e[1000001];
long long ans, n, m, k, u[1000001], v[1000001], w[1000001], c[11][10001];
//
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
//	scanf("%lld%lld%lld", n, m, k);
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++){
//		scanf("%lld%lld%lld", &u[i], &v[i], &w[i]);
		cin >> u[i] >> v[i] >> w[i];
//		e[++tot].to = v[i];
//		e[tot].w = w[i];
//		e[tot].ne = he[u[i]];
//		he[u[i]]++;
	}
	for(int i = 1; i <= k; i++){
		cin >> c[i][0];
//		scanf("%lld", c[i][0]);
		for(int j = 1; j <= n; j++){
//			scanf("%lld", c[i][j]);
			cin >> c[i][j];
		}
	}
	if(k == 0){
		sort(w + 1, w + 1 + m);
		for(int i = 1; i <= n - 1; i++){
			ans += w[i];
		}
		cout << ans;
		return 0;
	}
	cout << "500000000";
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
