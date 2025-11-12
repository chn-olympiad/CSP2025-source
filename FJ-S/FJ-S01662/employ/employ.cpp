#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 18;
const int MOD = 998244353;
int n,m;
string s;
bool vis[N];
int a[N];
int ans = 0;
void dfs(int l,int sum) {
	int f = l - sum;
	if (n-l+1 + sum < m) return;
	if (l >= n) {
		if (sum >= m) ans = (ans % MOD + 1) % MOD;
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (vis[i]) continue;
		if (s[l] == '0' || f >= a[i]) {
			vis[i] = true;
			dfs(l+1,sum);
			vis[i] = false;
		} else {
			vis[i] = true;
			dfs(l+1,sum+1);
			vis[i] = false;
		}
	}
}
signed main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m >> s;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	dfs(0,0);
	cout<<ans;
	return 0;
}