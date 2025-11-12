#include<bits/stdc++.h>
using namespace std;
int n,a[5005],mo = 998244353,dp[5005][5005],ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for (int i = 1;i <= n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	/**/if (n == 3){
		if (a[3] < a[1] + a[2]) cout<<1;
		return 0;
	}
	int sum = 0;
	for (int i = 1;i <= n;i++){
		if (sum > a[i]) dp[i][i] = 1;
		sum += a[i];
	}
	if (a[3] < a[1] + a[2]) dp[3][3] = 1;
	for (int i = 4;i <= n;i++){
		dp[i][3] = dp[i-1][3]+(i-1)*(i-2)/2;
		for (int j = i-1;j > 1;j--){
			for (int k = j-1;k >= 1;k--){
				if (a[k]+a[j] <= a[i]) dp[i][3]--;
			}
		}
	}
	for (int i = 4;i <= n;i++){
		for (int j = 4;j < i;j++){
			if (dp[i][j] == 0) dp[i][j] = (dp[i-1][j] + (dp[i][j-1] * (i-j+1))) % mo;
		}
	}
	/*for (int i = 1;i <= n;i++){
		for (int j = 1;j <= n;j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<"\n";
	}*/
	for (int i = 1;i <= n;i++){
		ans += dp[n][i];
		ans = ans % mo;
	}
	cout<<ans-1;
}