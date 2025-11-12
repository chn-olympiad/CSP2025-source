#include <iostream>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
const ull mod = 998244353;

int n, a[5005];
ull ans=0;
void dfs(int d, ull s, int m) {
	if (d == n) {
		if (s>2*m) ans=(ans+1)%mod;
		return;
	}
	if (d >= 3) {
		if (s>2*m) {
			ans = ((1<<(n-d))%mod+ans%mod)%mod;
			return;
		}
	}
	dfs(d+1, s+a[d]%mod, max(m, a[d]));
	dfs(d+1, s, m);
}

int main() {
	
	freopen("polygon.in", "r", stdin);
	freopen("polygon.ans", "w", stdout);
	
	cin >> n;
	for (int i=0;i<n;++i) {
		cin >> a[i];
	}
	sort(a, a+n, greater<int>());
	dfs(0, 0, 0);
	cout << ans;
	
	return 0;
}
