#include <queue>
#include <string>
#include <bits/stdc++.h>
#define ll long long 
#define int ll
#define fi first
#define se second
#define mk make_pair
#define mem(a , x) memset(a , x , sizeof(a))
#define ls x << 1
#define rs x << 1 | 1
using namespace std;
ll const N = 5e3 + 10 , mod = 998244353;
ll n , a[N] , dp[N] , ans , A , res = 1;
signed main(){
	freopen("polygon.in" , "r" , stdin);
	freopen("polygon.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 1;i <= n;i ++) cin >> a[i] , res *= 2 , res %= mod , A = max(a[i] , A);
	sort(a + 1 , a + n + 1) , res -- , dp[0] = 1;
	for (int i = 1;i <= n;i ++){
		ll sum = 0;
		for (int j = 0;j <= a[i];j ++) sum += dp[j];
		ans += sum , ans %= mod;
		for (int j = A;j >= a[i];j --) dp[j] += dp[j - a[i]] , dp[j] %= mod;
	}
	cout << (res - ans) % mod << "\n";
	return 0;
}
/*

*/