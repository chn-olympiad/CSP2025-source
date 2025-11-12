#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N_ = 2e6 + 5;
const int N = 5e5 + 5;
int Dp_sum[N_];
bool exist[N_];
int n, a[N], dp[N], sfx[N], k;
signed main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> k;
	for(int i = 1; i <= n; i++)cin >> a[i], sfx[i] = sfx[i - 1] ^ a[i];
	exist[0] = true;
	for(int i = 1; i <= n; i++){
		if(exist[sfx[i] ^ k])dp[i] = Dp_sum[sfx[i] ^ k] + 1;
		dp[i] = max(dp[i], dp[i - 1]);
		Dp_sum[sfx[i]] = max(Dp_sum[sfx[i]], dp[i]);
		exist[sfx[i]] = true;
	}
	cout << dp[n] << endl;
	return 0;
}
/*
Note

2025-11-1 9:11 Pass T3

Solution
一个很显然的dp，从 i - 1 或者满足区间异或和的左端点转移过来即可
前缀和优化，O(n)

Note
Nothing Here 
*/ 