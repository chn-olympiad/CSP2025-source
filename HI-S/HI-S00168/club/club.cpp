#include<bits/stdc++.h>
#define N 200010
using namespace std;
int n;
int v[N][4];
long long f[210][210][210];
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1; i <= n; i++)scanf("%d%d%d", &v[i][1], &v[i][2], &v[i][3]);
		memset(f, 0xcf, sizeof(f));
		long long ans = 0;
		f[0][0][0] = 0;
		f[1][0][0] = v[1][1];
		f[0][1][0] = v[1][2];
		f[0][0][1] = v[1][3];
		for(int i = 2; i <= n; i++){
			for(int j = (n / 2); j >= 0; j--){
				for(int k = (n / 2); k >= 0; k--){
					for(int p = (n / 2); p >= 0; p--){
						if(k + j + p > i)continue;
						if(j > 0) f[j][k][p] = max(f[j][k][p], f[j - 1][k][p] + v[i][1]);
						if(k > 0) f[j][k][p] = max(f[j][k][p], f[j][k - 1][p] + v[i][2]);
						if(p > 0) f[j][k][p] = max(f[j][k][p], f[j][k][p - 1] + v[i][3]);
						if(i == n) ans = max(ans, f[j][k][p]);	
					}
				}
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
} 
