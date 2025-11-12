#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int TN = 19,N = 505,mod = 998244353;
int n,m,a[N],dp[1 << TN][TN],cnt[N];
string s;
void solve1(){
	dp[0][0] = 1;
	for(int S = 1;S < (1 << n);S++){
		int pop = __builtin_popcount(S);
		for(int i = 1;i <= n;i++){
			if(S & (1 << i - 1)){
				for(int j = 0;j <= n;j++){
					int T = j + (s[pop] == '0' || a[i] <= j);
					dp[S][T] = (dp[S][T] + dp[S ^ (1 << i - 1)][j]) % mod;
				}
			}
		}
	}
	int ans = 0;
	for(int i = 0;i <= n - m;i++)ans = (ans + dp[(1 << n) - 1][i]) % mod;
	cout << ans;
}
void solve2(){
	int all = 1;
	for(int i = 1;i <= n;i++)all = all * i % mod;
	for(int i = 1;i <= n;i++)cnt[a[i]]++;
	for(int i = 1;i <= n;i++)cnt[i] += cnt[i - 1];
	int val = 1,now = 0;
	for(int i = 1;i <= n;i++){
		if(s[i] == '1'){
			if(now > cnt[i - 1])val = 0;
			else val = val * (cnt[i - 1] - (now++)) % mod;
		}
	}
	for(int i = 1;i <= n - now;i++)val = val * i % mod;
	cout << (all + mod - val) % mod;
}
void solve3(){
	for(int i = 1;i <= n;i++){
		if(s[i] == '0')return cout << 0,void();
	}
	if(*min_element(a + 1,a + n + 1) == 0)return cout << 0,void();
	int ans = 1;
	for(int i = 1;i <= n;i++)ans = ans * i % mod;
	cout << ans;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m >> s;
	s = " " + s;
	for(int i = 1;i <= n;i++)cin >> a[i];
	if(n <= 18)solve1();
	else if(m == 1)solve2();
	else solve3();
}
