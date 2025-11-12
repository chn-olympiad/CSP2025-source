#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int p = 998244353;
const int Max = 10049;
int n, a[5005], f[5005][10050], ans;
int cnt[10050];

signed main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	f[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= Max; j++) {
			f[i][min(Max, j + a[i])] = (f[i][min(Max, j + a[i])] + f[i - 1][j]) % p;
		}//?
		for (int j = 2 * a[i] + 1; j <= Max; j++) ans = (ans + f[i][j]) % p;
		for (int j = 0; j <= Max; j++) f[i][j] = (f[i][j] + f[i - 1][j]) % p;
		cnt[a[i]]++;
		for (int j = 1; j < i; j++) cnt[a[i] + a[j]]++;
		for (int j = 2 * a[i] + 1; j <= Max; j++) ans = (ans - cnt[j]) % p;
	}
	
	cout << ((ans % p) + p) % p << endl;
	
	return 0;
}
