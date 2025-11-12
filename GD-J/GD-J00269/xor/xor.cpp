#include<bits/stdc++.h>
using namespace std;
int n, m, a[500005], b[500005], ans;
int dp[500005];
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		b[i] = (b[i - 1] ^ a[i]);
//		cout << b[i] << " ";
	}
//	cout << (3 ^ 3) << endl;;
	for(int i = 1; i <= n; i++){
		for(int j = i; j >= 1; j--){
			int x = (b[i] ^ b[j - 1]);
			if(x == m){
				dp[i] = max(dp[i], dp[j - 1] + 1);
			}
			dp[i] = max(dp[i], dp[j - 1]);
		}
	}
	cout << dp[n];
	return 0;
}

