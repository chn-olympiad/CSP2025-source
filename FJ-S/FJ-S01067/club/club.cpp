#include <bits/stdc++.h>
#define File(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout)
#define max(x,y) ((x)>(y)?(x):(y))
#define max3(x,y,z) (max(max(x,y),z))
const int MAXN = 1e1 + 7;
int n, m, a[MAXN * 3][5], i, j, k;
int f[MAXN][MAXN][MAXN];
int main () {
	File("club");
	int T;
	scanf ("%d", &T);
//	T = 1;
	while (T--) {
		scanf ("%d", &n);
		for (m = n / 2, i = 0; i < n; i++) for (j = 0; j < 3; j++) scanf ("%d", &a[i][j]);
		memset(f, 0, sizeof f);
		for (i = 0; i < n; i++) {
			for (j = 0; j < m; j++) for (k = 0; k < m; k++) {
				if(((j+1+k)*2)>=i) f[i+1][j+1][k] = max(f[i+1][j+1][k], f[i][j][k] + a[i][0]);
				if(((j+1+k)*2)>=i) f[i+1][j][k+1] = max(f[i+1][j][k+1], f[i][j][k] + a[i][1]); 
				if(((j+k)*2)>=i)   f[i+1][j][k]   = max(f[i+1][j][k]  , f[i][j][k] + a[i][2]);
//				printf("%d:%d:%d==%d:%d:%d\n", i, j, k, f[i+1][j+1][k],f[i+1][j][k+1],f[i+1][j][k]);
			}
//				printf("i==%d\n",i+1);
//			for (j = 0; j < m + 1; j++) {
//				for (k = 0; k < m + 1; k++) printf("%d ",f[i+1][j][k]);
//				printf("\n");
//			}
				
		}
		int ans = 0;
		for (i = 0; i < m + 1; i ++) for (j = 0; j < m + 1; j++) ans = max(ans,f[n][i][j]);
		printf("%d\n", ans);
	}
	return 0;
}

