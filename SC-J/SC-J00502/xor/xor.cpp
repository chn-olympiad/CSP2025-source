#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 5e5 + 20;
int n, k, ans, a[N], num[N], dp[N];
map<ll, int> mp;

int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		num[i] = (num[i - 1] ^ a[i]);
	}
	mp[0] = 1;
	for(int i = 1; i <= n; i++){
		dp[i] = max(dp[i - 1], mp[num[i] ^ k]);
		mp[num[i]] = max(mp[num[i]], dp[i] + 1);
	}
	for(int i = 1; i <= n; i++) ans = max(ans, dp[i]);
	cout << ans;
	return 0;
}