/*********************
 ~AUTHOR BY "ILWF^_^"
 ~author by "ILWF^_^"
*********************/
#include<bits/stdc++.h>
#define ILW return
#define F 0
using namespace std;
using ll = long long;
const ll N = 500005 , M = 2000005;
const ll mod = 1e9 + 7;
ll a[N] , pre[N] , dp[N] , lst[N];
ll n , k;
void solve(){
	memset(lst , -1 , sizeof(lst));
	lst[0] = 0;
	cin >> n >> k;
	for(int i = 1;i <= n;i++) cin >> a[i] , pre[i] = pre[i - 1] ^ a[i];
	for(int i = 1;i <= n;i++){
		ll tar = pre[i] ^ k;
		if(lst[tar] != -1) dp[i] = max(dp[i - 1] , dp[lst[tar]] + 1);
		else dp[i] = dp[i - 1];
		lst[pre[i]] = i;
	}
	cout << dp[n];
}
int main(){
	freopen("xor.in" , "r" , stdin);
	freopen("xor.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll t = 1;
	//cin >> t;
	while(t--) solve();
	ILW F;
}
