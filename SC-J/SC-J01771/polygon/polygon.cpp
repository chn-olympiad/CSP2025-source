#include<bits/stdc++.h>
using namespace std;

const long long maxn = 5000 + 10, mod = 998244353;
long long n, ans, a[maxn];
bool all_1 = true;

void dfs(long long res, long long x, long long sum, long long maxlen){ // 当前正在考虑第 x 根木棍, 和为 sum, 最长木棍 maxlen
	if(x == n + 1){
		if(sum > 2 * maxlen && res >= 3) ans = (ans + 1) % mod;
		return;
	}
	if(sum > 2 * maxlen) return;
	if(res >= 3) ans++;
	dfs(res + 1, x + 1, sum + a[x], max(maxlen, a[x]));
	dfs(res, x + 1, sum, maxlen);
}

long long C(int n, int m){
	long long ans = 1; 
	for(int i = n; i >= n - m + 1; --i){
		ans = ans * i % mod;
	}
	for(int i = 1; i <= m; ++i) ans /= i;
	return ans % mod % mod;
}

void solve(){
	for(int i = 3; i <= n; ++i){
		ans = ans + C(n, i);
	}
	cout << ans;
}

int main(){
	
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	cin >> n;
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
		if(a[i] != 1) all_1 = false;
	}
	if(all_1){
		solve();
		return 0;
	}
	
	dfs(0, 1, 0, 0);
	cout << ans;
	return 0;
}