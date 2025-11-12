#include<bits/stdc++.h>
#define endl '\n'
#define pi piar<int, int>
#define ll long long

using namespace std;
const int mod = 998244353;
const int N = 5e3 + 10;
ll n, a[N], ma, ans, s[N];
bool b[N];

void dfs(int k, int len) {
	if (k > len) {
		ll sum = 0;
		for (int i = 1; i <= len; i++)
			if (b[i])
				sum += a[i];
		if (sum > ma) ans++;
		if (ans >= mod) ans -= mod;
		return ;
	}
	b[k] = false;
	dfs(k + 1, len);
	b[k] = true;
	dfs(k + 1, len);
	b[k] = false;
	return ;
}

int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n;
	bool flag = true;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] != 1ll) flag = false;
	}
	sort(a + 1, a + 1 + n);
	if (flag) {
		ll sum = 1ll;
		for (ll i = 1; i <= n; i++) sum = (sum * 2ll) % mod;
		sum --;
		sum -= n;
		for (ll i = 1; i < n; i++) sum = ((sum - i) % mod + mod) % mod;
		cout << sum << endl;
		return 0;
	}
//	if (n <= 500) {
//		for (int i = 1; i <= n; i++) if (a[i] > 100) flag = true;
//		if (!flag) {
//			for (int i = 1; i <= n; i++) b[a[i]]++, s[i] = s[i - 1] + a[i];
//			for (int i = 1; i <= 100; i++) {
//				if (!b[i]) continue;
//				int k = lower_bound(a + 1, a + 1 + n, i) - a;
//				for (int l = 1; l <= k; l++)
//					for (int r = l + 1; r <= k; r++) {
//						if ()
//					}
//			}
//			return ;
//		}
//	}
	for (int i = 3; i <= n; i++) {
		ma = a[i];
		dfs (1, i - 1);
	}
	cout << ans << endl;
	return 0;
}
