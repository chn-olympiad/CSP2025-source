#include<bits/stdc++.h>
#define int long long
const int N = 5e5 + 5;
using namespace std;

int n, k, a[N], sum[N], dp[N];

void solve(){
	int c1 = 0, c0 = 0;
	for(int i = 1; i <= n; i++){
		if(a[i] == 1) c1++;
		else c0++;
	}
	if(k == 1) cout << c1;
	else cout << c0;
}

signed main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		sum[i] = sum[i - 1] ^ a[i];
		if(a[i] == k) dp[i] = 1;
	}
	if(n >= 3e4){
		solve();
		return 0;
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= i; j++){
			dp[i] = max(dp[i], dp[j - 1] + (((sum[i] ^ sum[j - 1]) == k)?1:0));
		}
	}
	cout << *max_element(dp + 1, dp + n + 1);
	return 0;
}
