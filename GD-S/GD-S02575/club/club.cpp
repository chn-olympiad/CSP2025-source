#include<bits/stdc++.h>
using namespace std;
const int N = 206;
const int M = 1e5 + 5;
int dp[N][N/2][N/2][N/2];
int a[M][4];
int a2[M];

bool cmp(int x,int y){
	return x > y;
}

void solve(int n){
	for(int i = 1; i <= n; i++){
		scanf("%d%d%d", &a[i][1], &a[i][2], &a[i][3]);
	}
	int ans = INT_MIN;
	memset(dp, 0, sizeof(dp));
	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= i; j++){
			for(int k = 0; k <= i - j; k++){
				for(int l = 0; l <= i - j - k; l++){
					if(j <= n / 2 && j > 0){
						dp[i][j][k][l] = max(dp[i][j][k][l], dp[i - 1][j - 1][k][l] + a[i][1]);
					} 
					if(k <= n / 2 && k > 0){
						dp[i][j][k][l] = max(dp[i][j][k][l], dp[i - 1][j][k - 1][l] + a[i][2]);
					} 
					if(l <= n / 2 && l > 0){
						dp[i][j][k][l] = max(dp[i][j][k][l], dp[i - 1][j][k][l - 1] + a[i][3]);
					} 
					ans = max(dp[i][j][k][l], ans);
				}
			}
		}
	}
	printf("%d\n", ans);
}

void solve3(int n){
	
}

void solve2(int n){
	for(int i = 1; i <= n; i++){
		int fw1, fw2;
		scanf("%d%d%d", &a2[i], &fw1, &fw2);
		if(fw1 == 0 && fw2 == 0){
			continue;
		}else{
			solve3(n);
			return;
		}
	}
	sort(a2 + 1, a2 + n + 1, cmp);
	long long ans = 0;
	for(int i = 1; i <= n / 2; i++){
		ans += a2[i];
	}
	printf("%lld", ans);
}

int main(){
//	freopen("club2.in", "r", stdin);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int _T;
	scanf("%d", &_T);
	while(_T--){
		int _n;
		scanf("%d", &_n);
		if(_n <= 200){
			solve(_n);
		}else{
			solve2(_n); 
		}
	}
	return 0;
}
