#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 505, mod = 998244353;
string s;
int a[maxn];
signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n, m; cin >> n >> m;
	int ans = 1, tot = n;
	cin >> s;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		if(i - 1 >= a[i])
			tot--;
		else
			break;
	}
	if(m > tot) {
		cout << 0 << endl;
		return 0;
	}
	for (int i = 1; i <= tot; i++)
		ans = ans * i % mod;
	cout << ans << endl;
	return 0;
} 
