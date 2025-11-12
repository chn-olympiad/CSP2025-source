#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;
int n,m;
string s;
int c[5010];
int dp[(1<<18)][20],g[(1<<18)][20];
int flag1 = 0;
int jc[10010];
int sum[510][510];
signed main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	jc[0] = 1;
	for(int i=1;i<=1000;i++) jc[i] = (jc[i-1] * i) % mod; 
	cin >> n >> m;
	cin >> s;
	s = " " + s;
	for(int i=1;i<=n;i++) cin >> c[i];
	for(int i=1;i<=n;i++) {
		if(s[i] == '0') flag1 = 1;
	}
	if(n <= 18) {
		int maxn = (1<<n) - 1;
		dp[0][0] = 1;
		for(int i=0;i<n;i++) {
			for(int j=0;j<=maxn;j++) {
				for(int k=0;k<=i;k++) g[j][k] = dp[j][k],dp[j][k] = 0;
			}
			for(int j=0;j<=maxn;j++) {
				int x = j;
				int p = 0;
				while(x) p += (x&1),x >>= 1;
				if(p != i) continue;
				for(int k=0;k<=i;k++) {
					for(int l=1;l<=n;l++) {
						if((1<<(l-1))&j) continue;
						if(s[i+1] == '1') {
							if(c[l] > i - k) dp[j|(1<<(l-1))][k+1] = (dp[j|(1<<(l-1))][k+1] + g[j][k]) % mod;
							else dp[j|(1<<(l-1))][k] = (dp[j|(1<<(l-1))][k] + g[j][k]) % mod;
						}
						else {
							dp[j|(1<<(l-1))][k] = (dp[j|(1<<(l-1))][k] + g[j][k]) % mod;
						}
					}
				}
			}
		}
		int ans = 0;
		for(int i=m;i<=n;i++) ans = (ans + dp[maxn][i]) % mod;
		cout << ans << '\n';
	}
	else if(flag1 == 0) {
		cout << jc[n] << '\n';
	}
	else if(m == n) {
		for(int i=1;i<=n;i++) {
			if(c[i] == 0 || s[i] == '0') {
				cout << 0 << '\n';
				return 0;
			}
		}
		cout << jc[n] << '\n';
	}
	return 0;
}
