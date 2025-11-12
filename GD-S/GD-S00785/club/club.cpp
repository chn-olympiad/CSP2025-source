#include<bits/stdc++.h>
using namespace std;
int t, n, dp[2005][2005], ans;
struct dd{
	int a, b, c;
}d[2005];
bool cmp(dd x, dd y){
	return x.a > y.a;
}
int ck(){
	for(int i = 1;i <= n;i++){
		if(d[i].c != 0)
			return 0;
	}
	for(int i = 1;i <= n;i++){
		if(d[i].b != 0)
			return 1;
	}
	return 2;
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while(t--){
		ans = 0;
		for(int i = 1;i <= n;i++){
			d[i].a = d[i].b = d[i].c = 0;
			for(int j = 1;j <= n;j++){
				dp[i][j] = 0;
			}
		}
		cin >> n;
		for(int i = 1;i <= n;i++){
			cin >> d[i].a >> d[i].b >> d[i].c;
		}
		int ok = ck();
		if(ok == 2){
			sort(d + 1, d + n + 1, cmp);
			for(int i = 1;i <= n / 2;i++){
				ans += d[i].a;
			}
			cout << ans << endl; 
		}
		if(ok == 1){
			dp[0][0] = 0;
			for(int i = 1;i <= n;i++){
			for(int j = n / 2;j >= 1;j--){
			for(int k = n / 2;k >= 1;k--){
				dp[j][k]=max(dp[j-1][k] + d[i].b, dp[j-1][k-1] + d[i].a);
			}
			}
			}
			ans = -1;
			for(int i = 1;i <= n / 2;i++){
				ans = max(ans, dp[n/2][i]);
			}
			cout << ans;
		}
	}
	return 0;
}
