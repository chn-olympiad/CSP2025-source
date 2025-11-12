#include <bits/stdc++.h>
using namespace std;
int n, m, k, ans;
int u[1000005], v[1000005], w[1000005], c[15][100005];
int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout); 
    scanf("%d %d %d", &n, &m, &k);
    for(int i=1; i<=m; i++){
		scanf("%d %d %d", &u[i], &v[i], &w[i]);
		ans+=w[i];
	}
	for(int i=1; i<=k; i++){
		scanf("%d", &c[i][0]);
		for(int j=1; j<=n; j++)
		    scanf("%d", &c[i][j]);
	}
	printf("%d\n", ans);
    return 0;
}  
