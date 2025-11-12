#include<bits/stdc++.h>
using namespace std;
const int N = 1e4+11, M=1e6+11;
int u[M], v[M], w[M], c[11], a[11][N], ans =0;


int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k, ans=0;
	scanf("%d%d%d", &n, &m, &k);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d", &u[i], &v[i], &w[i]);
		ans+=w[i];
	}
	for(int i=1;i<=k;i++){
		scanf("%d", &c[i]);
		for(int j=1;j<=n;j++){
			scanf("%d", &a[i][j]);
		}
	}
	printf("%d\n", ans);
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
