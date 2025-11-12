#include<bits/stdc++.h>
#define itn int
#define pii pair<int,int>
#define el cout<<"\n"
#define fi first
#define se second
#define N 500010
//#define int long long
using namespace std;
int n, k, a[N], now, ans;
map<int, int>mp;
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	mp[0] = 1;
	for (itn i = 1; i <= n; i++) {
		cin >> a[i];
		now ^= a[i];
		if (mp[k^now]) {
			ans++;
			mp.clear();
			now = 0;
		}
		mp[now] = 1;
	}
	cout << ans;
	return 0;
}