#include <bits/stdc++.h>
using namespace std;
#define in(s) freopen(s,"r",stdin)
#define out(s) freopen(s,"w",stdout)
const int N = 205;
const int M = 105;

int n,m;
int arr[100005][5];
int dp[M][M][M];
int da[100005];
int ans;
bool flag;

void mian(){	// 1~11  55分 
	scanf("%d",&n);
	ans = 0;
	m = n>>1;
	flag = 1;
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&arr[i][1],&arr[i][2],&arr[i][3]);
		if (arr[i][2] || arr[i][3]){
			flag = 0;
		}
	}
	if (flag){ // 特殊性质A   12  5分 
		cout << 1;
		for(int i=1;i<=n;i++){
			da[i] = arr[i][1];
		}
		sort(da+1,da+n+1);
		for(int i=n;i>=m;i--){
			ans += da[i];
		}
		printf("%d",ans);
		return;
	}else{
		for(int i=0;i<=m;i++){
			for(int j=0;j<=m;j++){
				for(int k=0;k<=m&&i+j+k<=n;k++){
					dp[i][j][k] = 0;
					if (i)	dp[i][j][k] = max(dp[i][j][k],dp[i-1][j][k]+arr[i+j+k][1]);
					if (j)	dp[i][j][k] = max(dp[i][j][k],dp[i][j-1][k]+arr[i+j+k][2]);
					if (k)	dp[i][j][k] = max(dp[i][j][k],dp[i][j][k-1]+arr[i+j+k][3]);
					ans = max(ans,dp[i][j][k]);
				}
			}
		}
		printf("%d\n",ans);
		return;
	}
	
}

int main(){
	in("club.in");
	out("club.out");
	int T;
	scanf("%d",&T);
	while (T--){
		mian();
	}
	return 0;
}


/*

*/
