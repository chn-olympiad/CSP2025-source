#include <iostream>
using namespace std;
int n,m;
bool s[503],f[503];
int c[503];
long long ans = 0;
long long mul[503];
const int mod = 998244353;
void dfs(int p,int cntf,int cntt) {
	if (p > n) {
		if (cntt >= m)    ans = (ans + 1) % mod;
		return;
	}
	if (cntt >= m) {
		ans = (ans + mul[n - p + 1]) % mod;
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (f[i])    continue;
		if (cntf >= c[i]) {
			f[i] = true;
			dfs(p + 1,cntf + 1,cntt);
			f[i] = false;
		} else {
			if (!s[p]) {
				f[i] = true;
				dfs(p + 1,cntf + 1,cntt);
				f[i] = false;
			} else {
				f[i] = true;
				dfs(p + 1,cntf,cntt + 1);
				f[i] = false;
			}
		}
	}
}
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		char x;
		cin >> x;
		s[i] = x - '0';
	}
	mul[0] = 1;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
		mul[i] = mul[i - 1] * i % mod;
	}
	dfs(1,0,0);
	cout << ans;
	return 0;
}
