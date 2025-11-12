#include <bits/stdc++.h>
using namespace std;


int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	int n, m;
	cin >> n >> m;
	int ihard[n + 1] = {};
	int people[n + 1] = {};
	char chard[n + 1] = {};
	for(int i = 1; i <= n; i++) cin >> chard[i];
	for(int i = 1; i <= n; i++) ihard[i] = chard[i] - '0';
	for(int i = 1; i <= n; i++) cin >> people[i];
	int dp[n + 1][m + 1] ={};
	long long ftemp = 1;
	long long stemp = 1;
	long long temp = 1;
	for(int i = n; i <= m; i++) ftemp = ftemp * i;
	for(int i = 1; i <= n; i++) stemp = stemp * i;
	temp = ftemp / stemp;
	int ans = temp % 998244353;
	cout << ans;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
