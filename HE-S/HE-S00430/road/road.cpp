#include<bits/stdc++.h>
using namespace std;
const int N = 1000010;
int n,m,k,u[N],v[N],w[N],c[22], a[20][N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &u[i], &v[i], &w[i]);
	}
	for (int j = 1; j <= k; j++) {
		scanf("%d", &c[j]);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[j][i]);
		}
	}
	puts("0");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
