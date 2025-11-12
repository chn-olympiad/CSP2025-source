/*********************
 ~AUTHOR BY "ILWF^_^"
 ~author by "ILWF^_^"
*********************/
#include<bits/stdc++.h>
#define ILW return
#define F 0
using namespace std;
using ll = long long;
const ll N = 5005 , M = 10005;
const ll mod = 998244353;
ll a[N] , dp[N][M];
ll n , m , q;
ll ans = 0;
void solve(){
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> a[i];
	sort(a + 1 , a + n + 1);
	dp[0][0] = 1;
	for(int i = 1;i <= n;i++){
		for(int j = 0;j <= 10001;j++){
			ll res = j + a[i];
			if(res >= 10001) dp[i][10001] = (dp[i][10001] + dp[i - 1][j]) % mod;
			else dp[i][res] = (dp[i][res] + dp[i - 1][j]);
		}
		for(int j = 2 * a[i] + 1;j <= 10001;j++) ans = (ans + dp[i][j]) % mod;
		for(int j = 0;j <= 10001;j++) dp[i][j] = (dp[i][j] + dp[i - 1][j]) % mod;
	}
	cout << ans;
}
int main(){
	freopen("polygon.in" , "r" , stdin);
	freopen("polygon.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll t = 1;
	//cin >> t;
	while(t--) solve();
	ILW F;
}
