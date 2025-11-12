#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N = 5e5 + 5;
int n, k, a[N], pre[N];
signed main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	pre[1] = a[1];
	for(int i = 2; i <= n; i++) {
		pre[i] = (pre[i - 1] ^ a[i]);
	}
	int ans = 0;
	map<int, int> mp;
	mp[0] = 1;
	for(int i = 1; i <= n; i++) {
		int nd = (k ^ pre[i]);
		if(mp[nd] || a[i] == k) {
			ans++;
			mp.clear();
		}
		mp[pre[i]] = i;
	}
	cout << ans << endl;
	return 0;
}