#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[1000010];
int n;
int ans = 0;
int cnt = 0, sum = 0, maxx = 0;
const int mod = 998244353;
void dfs(int u){
	if(u > n){
		if(sum > 2 * maxx && cnt >= 3)ans++;
		return;
	}
	cnt++;
	sum += a[u];
	int t = maxx;
	maxx = max(a[u], maxx);
	dfs(u + 1);
	sum -= a[u];
	cnt--;
	maxx = t;
	dfs(u + 1); 
}
int fast_pow(int a, int b){
	if(b == 0)return 1;
	int t = fast_pow(a, b / 2) % mod;
	if(b % 2 == 1){
		return ((t * t) % mod * a) % mod;
	}
	else return (t * t) % mod;
}
signed main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int maxnum = 0;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		maxnum = max(a[i], maxnum);
	}
	if(maxnum != 1)dfs(1);
	else {
		ans = ((fast_pow(2, n) - n + mod) % mod - n * (n - 1) / 2 - 1) % mod;
	}
	cout << ans << endl;
}
