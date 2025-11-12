#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5005, Mod = 998244353;
int n, a[N], dp[N * N], ans, sum;
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		sum += a[i];
	}
	sort(a + 1, a + n + 1);
	dp[0] = 1;
	for(int i = 1;i <= n;i++){
		for(int j = sum;j >= a[i];j--){
			dp[j] = (dp[j] + dp[j - a[i]]) % Mod;
			if(j > a[i] * 2) ans = (ans + dp[j - a[i]]) % Mod;
		}
	}
	cout << ans;
	return 0;
}
//O(n^2*max_a[i])
