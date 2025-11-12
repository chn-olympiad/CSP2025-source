#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<map>
using namespace std;
typedef long long ll;
const ll N = 105;
ll dp[N][N][N];
ll n, a[N][4], t, b[N];
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while(t--){
		cin >> n;
		ll ans = -2e17;
		bool ok = 0;
		for(int i = 1; i <= n; i++){
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			if(a[i][3] != a[i][2] || a[i][2] != 0){
				ok = 1;
			}
		}
		if(!ok && n == (ll)1e5){
			for(int i = 1; i <= n; i++){
				b[i] = a[i][1];
			}
			sort(b + 1, b + n + 1);
			ans = 0;
			for(int i = n; i > n / 2; i--){
				ans += b[i];
			}
			cout << ans << "\n";
			continue;
		}
		for(int i = 0; i <= n / 2; i++){
			for(int j = 0; j <= n / 2; j++){
				for(int k = 0; k <= n - i - j && k <= n / 2; k++){
					dp[i][j][k] = 0;
					if(i){
						dp[i][j][k] = dp[i - 1][j][k] + a[i + j + k][1];
					}
					if(j){
						dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][k] + a[i + j + k][2]);
					}
					if(k){
						dp[i][j][k] = max(dp[i][j][k], dp[i][j][k - 1] + a[i + j + k][3]);
					}
				}
			}
		}
		for(int i = 1; i <= n / 2; i++){
			for(int j = 1; j <= n / 2; j++){
				ans = max(ans, dp[i][j][n - i - j]);
			}
		}
		cout << ans << "\n";			
	}	
	return 0;
}
