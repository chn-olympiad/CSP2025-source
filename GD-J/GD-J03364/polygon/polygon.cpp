#include <bits/stdc++.h>
using namespace std;

#define int long long
#define N 5010

const int mod = 998244353;
int n, a[N];
bool f[N];
int dp[810][810];
//dp[i][j]表示前i个数选了j个1,(i-j)个0的方案数  
int ans = 0;
void dfs(int k) {
	if(k == n + 1) {
		int sum = 0;
		int mx = -1;
		int cnt = 0;
		for(int i = 1;i <= n;i++) {
			if(f[i] == true) {
				sum += a[i];
				mx = max(mx, a[i]);
				cnt++;
			}
		}
		if(sum > mx * 2 && cnt >= 3) {
			ans = (ans + 1) % mod;
		}
		return;
	}
	f[k] = true;
	dfs(k + 1);
	
	f[k] = false;
	dfs(k + 1);
}
signed main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	bool At = true;
	for(int i = 1;i <= n;i++) {
		cin >> a[i];
		if(a[i] > 1) {
			At = false;
		}
	}
	if(n >= 10 && At == true) {
		//均为0或1 
		//用dp解决较好  
		//0边相当于没选  
		
		//如果选全0,不行 
		//如果选有1,那么1的个数>2
		
		dp[0][0] = 1;
		for(int i = 1;i <= n;i++) {
			for(int j = 1;j <= i;j++) {
				//不选  
				dp[i][j] += dp[i - 1][j];
				//选 
				dp[i][j] += dp[i - 1][j - (a[i] == 1)];
			}
		}
		
		int aans = 0;
		for(int i = 1;i <= n;i++) {
			for(int j = 3;j <= i;j++) {
				aans += dp[i][j];
			}			
		}
		
		cout << aans << "\n";
	} else if(n <= 10) {
		dfs(1);
		cout << ans << "\n";
	} else {
		
	}
	return 0;
}
