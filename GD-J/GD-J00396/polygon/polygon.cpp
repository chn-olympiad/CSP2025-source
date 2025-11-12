#include<bits/stdc++.h>
using namespace std;
int n, ans = 0, mp[5005];
int dfs(int now, int mx, int sum){
	if(now == n + 1) return mx * 2 < sum;
	return dfs(now + 1, mx, sum) % 998244353 + dfs(now + 1, max(mx, mp[now]), sum + mp[now]) % 998244353;
}
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int mx = 0;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> mp[i];
		mx = max(mx, mp[i]);
	}
	if(mx == 1){
		cout << ((1 << n) - 1 - n - n * (n - 1) / 2) % 998244353;
		return 0;
	}
	cout << dfs(1, 0, 0);
	return 0;
}
