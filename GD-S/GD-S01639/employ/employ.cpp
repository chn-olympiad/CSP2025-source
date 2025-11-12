/*********************
 ~AUTHOR BY "ILWF^_^"
 ~author by "ILWF^_^"
*********************/
#include<bits/stdc++.h>
#define ILW return
#define F 0
using namespace std;
using ll = long long;
const ll N = 505 , M = (1ll << 20);
const ll mod = 998244353;
string s;
ll vis[N] , a[N] , c[N];
ll n , m , q;
ll ans = 0;
void dfs(ll pos){
	if(pos == n + 1){
		ll cnt = 0 , no = 0;
		for(int i = 1;i <= n;i++){
			if(c[a[i]] <= no) no++;
			else if(s[i] == '0') no++;
			else if(s[i] == '1') cnt++;
		}
		ans = (ans + (cnt >= m)) % mod;
		ILW;
	}
	for(int i = 1;i <= n;i++){
		if(vis[i] == 0){
			a[pos] = i;
			vis[i] = 1;
			dfs(pos + 1);
			vis[i] = 0;
		}
	}
}
void solve1(){
	dfs(1);
	cout << ans;
}
//ll dp[N][M];
//void solve2(){
//	dp[0][0] = 1;
//	for(int i = 1;i <= n;i++){
//		for(int j = 0;j < (1ll << n);j++){
//			ll giup = i - 1 - j;
//			for(int k = 1 , wa = 1;k <= n;wa <<= 2){
//				if((wa & j) == 0){
//					dp[i][j] = (dp[i][j] + dp[])
//				}
//			}
//		}
//	}
//}
void solve(){
	cin >> n >> m >> s;
	ll ze = 0;
	for(int i = 1;i <= n;i++) cin >> c[i] , ze += (c[i] == 0);
	s = ' ' + s;
	bool flag = true;
	for(int i = 1;i <= n;i++) if(s[i] == '0') flag = false;
	if(n <= 11) solve1();
	if(flag == true){
		if(m <= n - ze){
			ll res = 1;
			for(int i = 1;i <= n;i++) res = (res * i) % mod;
			cout << res;
		}else cout << 0;
	}
}
int main(){
	freopen("employ.in" , "r" , stdin);
	freopen("employ.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll t = 1;
	//cin >> t;
	while(t--) solve();
	ILW F;
}
