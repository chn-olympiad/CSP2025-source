#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<unordered_map>
using namespace std;

const int MAXN = 5e3 + 5;
const long long MOD = 998244353;
int a[MAXN],n;
unordered_map<long long,long long> dp[2][MAXN][4];
//                                    t   pre  cnt
long long sum[MAXN];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin >> n;
	bool flag = 1;
	for(int i = 1;i <= n;i++) cin >> a[i],flag = flag && (a[i] == 1);
	if(flag){
		long long aans = 1;
		for(int i = 1;i <= n;i++) aans = aans * 2 % MOD;
		aans -= (1ll * n * (n - 1) / 2 % MOD + n) % MOD + 1;
		aans = (aans % MOD + MOD) % MOD;
		cout << aans;
		return 0;
	}
	sort(a + 1,a + n + 1);
	for(int i = 1;i <= n;i++) sum[i] = sum[i-1] + a[i];
	dp[0][0][0][0] = 1;
	long long ans = 0;
	int t = 0;
	for(int i = 0;i < n;i++){
		// dp[t^1].clear();
		// memset(dp[t^1],0,sizeof(dp[t^1]));
		// if(t == 0) cout << i << ' ' << dp[1][1][3][1] << '\n';
		for(int j = 0;j <= i;j++)// pre
			for(int l = 0;l <= 3;l++){
				for(auto nowp : dp[t][j][l]){
					int k = nowp.first;
					// cout << i << ' ' << j << ' ' << k << ' ' << l << '\n';
					long long now = dp[t][j][l][k];
					// cerr << i << ' ' << j << ' ' << k << ' ' << now << '\n';
					// cerr << i << ' ' << j << ' ' << k << ' ' << l << ' ' << now << '\n';
					(dp[t^1][j][l][k] += now) %= MOD;
					if(a[j] == a[i+1]){
						(dp[t^1][i+1][min(3,l+1)][k+a[i+1]] += now) %= MOD;
						// cerr << "    -> " << i + 1 << ' ' << i + 1 << ' ' << k + a[i+1] << '\n';
					}
					else{
						long long to = k + a[i+1] - 2 * (a[i+1] - a[j]);
						// if(to <= 0) continue;
						(dp[t^1][i+1][min(3,l+1)][to] += now) %= MOD;
						// cerr << "    -> " << i + 1 << ' ' << i + 1 << ' ' << to << '\n';
					}
				}
				dp[t][j][l].clear();
			}
		// if(t == 0) cout << i << ' ' << dp[1][1][3][1] << '\n';
		t ^= 1;
	}
	// cerr << "i pre sum val\n";
	// for(int j = 0;j <= n;j++)
		// for(auto k : dp[t][j][3])
			// cerr << n << ' ' << j << ' ' << k.first << ' ' << k.second << '\n';
	for(int i = 0;i <= n;i++)
		for(auto j : dp[t][i][3])
			if(j.first > 0) (ans += j.second) %= MOD;
	cout << ans;
	return 0;
}