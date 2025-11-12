#include <bits/stdc++.h>
using namespace std;
int a[505], cnt[505];
long long dp[505][505];

int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n, m, fail=0;
	cin >> n >> m;
	string s;
	cin >> s;
	for(int i=1;i<=n;++i){
		cin >> a[i];
	}
	for(int i=1;i<=n;++i){
		for(int j=0;j<a[i];++j){
			cnt[j]++;
		}
	}
	int id = 0;
	for(int i=0;i<n;++i){
		if(s[i]=='1'){
			id = i+1;
			dp[i+1][1] = cnt[i];
			break;
		}
	}
	for(int i=id+1;i<=n;++i){
		if(s[i-1]=='0') fail++;
		for(int j=1;j<=i-fail;++j){
			if(s[i-1]=='0') dp[i][j] = dp[i-1][j];
			if(s[i-1]=='1') dp[i][j] = dp[i-1][j]+(dp[i-1][j-1]-1)*cnt[fail];
			dp[i][j] %= 998244353;
		}
	}
	long long ans = 0;
	for(int i=m;i<=n;++i){
		ans += dp[n][i];
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
