#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e3 + 5;
const int MOD = 998244353;
int n,m;
int c[MAXN];
unsigned long long dp[MAXN];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cin >> n >> m;
	string s;
	cin >> s;
	for(int i = 1;i <= n;i++){
		cin >> c[i];
	}
	dp[1] = 1;
	for(int i = 2;i <= n;i++){
		dp[i] = dp[i - 1] * i % MOD;
	}
	cout << dp[n] % MOD << '\n';
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

