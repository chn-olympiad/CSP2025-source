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
ll const N = 5e5 + 10 , M = 2e6 + 10;
ll n , k , sum[N] , dp[N] , maxx[M] , A;
signed main(){
	freopen("xor.in" , "r" , stdin);
	freopen("xor.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	for (int i = 1 , x;i <= n;i ++){
		cin >> x;
		sum[i] = sum[i - 1] ^ x;
	}
	A = 2e6;
	for (int i = 1;i <= A;i ++) maxx[i] = -1;
	for (int i = 1;i <= n;i ++){
		dp[i] = dp[i - 1] + ((sum[i] ^ sum[i - 1]) == k);
		ll j = sum[i] ^ k;
		dp[i] = max(dp[i] , maxx[j] + 1);
		maxx[sum[i]] = max(maxx[sum[i]] , dp[i]);
	}
	cout << dp[n] << "\n";
	return 0;
}
/*

*/