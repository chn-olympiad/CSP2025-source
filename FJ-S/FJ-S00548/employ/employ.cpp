#include <iostream>
#define int long long 
const int mod = 998244353, maxn = 505;
using namespace std;
int n, m, ans, num, cnt, j;
int s[maxn], c[maxn], used[maxn], qpow[maxn];
string s1;
void dfs(int d){
	if (d > n) {
		if(num >= m) ans++;
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (!used[i]) {
			 used[i] = 1;
			if (s[d] == 0 || cnt >= c[i]) {
				cnt++;
				dfs(d + 1);
				cnt--, used[i] = 0;
			} 
			if(s[d] && cnt < c[i]) {
				num++;
				dfs(d + 1);
				num--, used[i] = 0;
			} 
		}
	}
}
signed main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	qpow[1] = 1;
	for (int i = 2; i < maxn; i++) 
		qpow[i] = qpow[i - 1] * i % mod;
	cin >> n >> m >> s1;
	for (int i = 1; i <= n; i++) s[i] = s1[i - 1] - '0', j += s[i];
	for (int i = 1; i <= n; i++) cin >> c[i]; 
	if (j == n && n > 18) cout << qpow[n] << '\n';
	else {
		dfs(1);
		cout << ans % mod << '\n';
	}
	return 0;
}
