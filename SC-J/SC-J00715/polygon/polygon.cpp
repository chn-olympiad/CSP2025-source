#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 998244353;
ll n, a[5005], f[5005];
ll ans;
void dfs (ll k, ll sum, ll mx, ll cnt){
	if (k >= 3 && sum > mx * 2)
		ans ++, ans %= mod;
	if (k > n)
		return;
	for (int i = cnt; i <= n; i ++){
		if (f[i] == 0){
			f[i] = 1;
			dfs (k + 1, sum + a[i], max (mx, a[i]), i);
			f[i] = 0;
		}	
	}
	return;
}
void dfs2 (ll k, ll cnt){
	if (k >= 3){
		ans ++;
		ans %= mod;
	}	
	if (k > n)
		return;
	for (int i = cnt; i <= n; i ++){
		if (f[i] == 0){
			f[i] = 1;
			dfs2 (k + 1, i);
			f[i] = 0;
		}	
	}
}
int main (){
	freopen ("polygon.in", "r", stdin);
	freopen ("polygon.out", "w", stdout);
	ios :: sync_with_stdio (false);
	cin.tie (0), cout.tie (0);
	cin >> n;
	int g = 1;
	for (int i = 1; i <= n; i ++)
		cin >> a[i];
	for (int i = 1; i <= n; i ++){
		if (a[i] != 1){
			g = 0;
			break;
		}
	}
	if (g){
		dfs2 (0, 1);
		cout << ans % mod;
		return 0;
	}		
	dfs (0, 0, -1, 1);
	cout << ans % mod;
	return 0;  
} 
