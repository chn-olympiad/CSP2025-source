#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int mod = 998244353;
const int maxn = 5010;
int a[maxn],s[maxn],dp[maxn][maxn];
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		s[i] = s[i-1] + a[i];
	}
	if(n <= 2){
		cout << 0 << endl;
		return 0;
	}
	for (int i = 1; i <= n; i++){
		dp[i][i] = a[i];
		for (int j = i; j <= n; j++){
			for (int k = i; k <= j; k++){
				dp[i][j] = max(dp[i][k],dp[k+1][j]);
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++){
		for (int j = i + 3; j <= n; j++){
			for (int k = i; k <= j; k++){
				if(s[j] - s[i-1] > 2 * dp[i][j]) ans++;
			}
		}
	}
	cout << ans << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
