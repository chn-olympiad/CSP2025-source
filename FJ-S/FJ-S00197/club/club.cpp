#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int T, n, a[3][N], dp[101][101][101], dp2[3001][3001];
bool f, f2;

bool cmp(int a, int b){
	return a > b;
}

void solve_A(){
	sort(a[0] + 1, a[0] + 1 + n, cmp);
	int ans = 0;
	for(int i = 1; i <= (n >> 1); ++i) ans += a[0][i];
	printf("%d\n", ans);
}

void solve_B(){
	for(int i = 0; i <= (n >> 1); ++i)
		for(int j = 0; j <= (n >> 1); ++j)
		    dp2[i][j] = 0;
	int m = n / 2; 
	for(int i = 1; i <= n; ++i)
	    for(int j = m; j >= 0; --j)
	    	for(int k = m; k >= 0; --k){
	    		if(j) dp2[j][k] = max(dp2[j][k], dp2[j - 1][k] + a[0][i]);
	    		if(k) dp2[j][k] = max(dp2[j][k], dp2[j][k - 1] + a[1][i]);
			}
	printf("%d\n", dp2[m][m]);
}

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &T);
	while(T--){
		f = 1; f2 = 1;
		for(int i = 0; i <= (n >> 1); ++i)
		    for(int j = 0; j <= (n >> 1); ++j)
		        for(int k = 0; k <= (n >> 1); ++k)
				    dp[i][j][k] = 0; 
		scanf("%d", &n);
		for(int i = 1; i <= n; ++i){
			scanf("%d%d%d", &a[0][i], &a[1][i], &a[2][i]);
			if(a[1][i] != 0 || a[2][i] != 0) f = 0;
			if(a[2][i] != 0) f2 = 0;
		}
		if(f){
			solve_A();
			continue;
		}
		if(f2){
			solve_B();
			continue;
		}
		int m = n / 2;
		for(int i = 1; i <= n; ++i)
			for(int j = m; j >= 0; --j)
				for(int k = m; k >= 0; --k)
					for(int o = m; o >= 0; --o){
						if(j) dp[j][k][o] = max(dp[j][k][o], dp[j - 1][k][o] + a[0][i]);
						if(k) dp[j][k][o] = max(dp[j][k][o], dp[j][k - 1][o] + a[1][i]);
						if(o) dp[j][k][o] = max(dp[j][k][o], dp[j][k][o - 1] + a[2][i]);
					}
		printf("%d\n", dp[m][m][m]);
	}
	return 0;
} 

/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/

