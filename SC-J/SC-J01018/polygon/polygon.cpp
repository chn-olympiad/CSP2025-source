#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define MAXN 5005
#define MAXM ((1 << 20) + 5)
#define pii pair<int, int>
#define mod 998244353

int n;
int l[MAXN];

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> l[i];
	}
	//mod!!!
	if (n <= 20) {
		int ans = 0;
		for (int i = 0; i <= (1 << n) - 1; ++i) {
			int maxl = 0;
			int suml = 0;
			for (int j = 1; j <= n; ++j) {
				if (1 << (j - 1) & i) {
					suml += l[j];
					maxl = max(maxl, l[j]);
				}
			}
			if (suml > 2 * maxl)
				ans = (ans + 1) % mod;
		}
		cout << ans << endl;
	}
	return 0;
}