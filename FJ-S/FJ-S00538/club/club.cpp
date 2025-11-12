#include <bits/stdc++.h>
using namespace std;

bool cmp(int x,int y){
	retuen x > y;
}
int main(){
	freopen("club.in","r",stdin);freopen("club.out","w",stdout);
	int t;cin >> t;
	while(t--){
//		int n;
//	int ans = 0;
//	const int N = 1e5 + 7;
//	int a[3][N];
//	int dp[N];
//	int f[3];
//	bool c[3][N];int minn;
//	for(int i = 1;i <= n;i++){
//		cin >> a[1][i] >> a[2][i] >> a[3][i];
//	}
//	for(int i = 1;i <= n;i++){
//		for(int j = 1;j <= 3;j++){
//			if(f[j] <= n/2){
//				dp[i] = max(dp[i],dp[i-1]+a[j][i]);
//			}
//			else{
//				for(int k = 1;k < i;k++){minn = 100000000;
//					if(c[j][i]) minn = min(minn,a[j][k]);
//				}if(minn < a[j][i]){for(int k = 1;k < i;k++){
//					if(a[j][k] == minn && a[j][i] != minn){
//						a[j][k] = a[j][i];
//						a[j][i] = minn;
//					}
//				}dp[i] = max(dp[i],dp[i-1]+a[j][i] - minn);
//				}
//				
//			}
//		}
//		if(dp[i] == dp[i-1]+a[1][i]) {c[1][i] = 1;
//		f[1]++;}
//		if(dp[i] == dp[i-1]+a[2][i]) {c[2][i] = 1;
//		f[2]++;}
//		if(dp[i] == dp[i-1]+a[3][i]) {c[3][i] = 1;
//		f[3]++;}
//	}
//	for(int i = 1;i <= n;i++){
//		ans += dp[i];
//	}
//	cout << ans;
	int n;cin >> n;
	int a[100005][3];
	bool f1 = 1;
	bool f2 = 1;
	for(int i = 1;i <= n;i++){
		cin >> a[i][1] >>a[i][2] >> a[i][3];
		if(a[i][2] != 0) f1 = 0;
		if(a[i][3] != 0) f2 = 0;
	}
	int maxn,sum[201][201];
	if(f2){
		if(f1){int b[100005]
			for(int i = 1;i <= n;i++){
				b[i] = a[i][1];
			}
			sort(b+1,b+n+1,cmp);
			for(int i = 1;i <= n /2;i++){
				maxn += b[i];
			}
		}
	}
	if(n <= 100000){
		for(int i = 1;i <= n/2;i++){
			for(int j = 1;j <= n/2;j++){
				sum[i][j] += a[1][i];
				sum[i][j] += a[2][j];
				sum[i][j] += a[3][n - i-j];
			}
		}
	}
	cout << maxn;
    }
	return 0;
}