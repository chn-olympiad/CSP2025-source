#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e3 + 10;
const int mod = 998244353;
int n, a[N], ans, mx = 0;
int dp[N][N];//j根棍子，最大值为k 
bool b[N];
void dfs(int step){
	if(step == n + 1) {
		int sum = 0, mx = 0, cnt = 0;
		for(int i = 1; i <= n; i++) {
			if(b[i]) {
				sum += a[i];
				mx = max(mx, a[i]);
				cnt++;
			}
		}
		if(sum > 2 * mx && cnt > 2) ans++;
	} else {
		b[step] = true;
		dfs(step + 1);
		b[step] = false;
		dfs(step + 1);
	}
}
signed main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout); 
	ios :: sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	if(n < 25) {//O(2^n)暴力火车头 
		dfs(1);
		cout << ans << endl;
		return 0;
	}
	for(int i = 1; i <= n; i++) mx = max(mx, a[i]);
	if(mx == 1) {
		//由于都是1肯定能组成解 
		ans = 1;
		for(int i = 1; i <= n; i++){
			ans *= 2;//这里好像不用快速幂 
			ans %= mod;
		}//所有排列 
		ans -= 1;//一条边都不选的情况 
		ans -= n;//只选一条边的情况 
		ans -= n * (n - 1) / 2;//只选两条边的情况 
		ans %= mod;
		cout << ans << endl; 
	} 
	return 0;
}
