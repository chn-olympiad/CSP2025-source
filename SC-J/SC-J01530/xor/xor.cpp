#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define ull unsigned long long
using namespace std;
ll n, k;
bool vis[500005];
ll a[500005];
ll dp[500005];
// dp[i] 表示前 i 个数字的区间最大值 
ll calc(ll x){
	ll ans = a[x];
	for(int i = x; i >= 1; i --){
		if(vis[i]) return -1;
		if(ans == k){
			vis[i] = true;
			return x - i;
		}
		ans ^= a[i - 1];
	}
	return -1;
}
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> k;
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
	}
	memset(vis, false, sizeof vis);
	for(int i = 1; i <= n; i ++){
		ll c = calc(i);
//		cout << c << " ";
		if((c >= 0) && ((i - c - 1) >= 0)){
			if(dp[i - c - 1] + 1 > dp[i - 1]){
//				cout << c << " " << i - c - 1 << " " << i << endl;
				dp[i] = dp[i - c - 1] + 1;	
			} else {
				dp[i] = dp[i - 1];
			}
		} else {
			dp[i] = dp[i - 1];
		}
//		cout << dp[i - 1] << " " << dp[i - c - 1] + 1 << " " << dp[i] << " " << i << endl;
	}
	cout << dp[n];
	return 0;
}