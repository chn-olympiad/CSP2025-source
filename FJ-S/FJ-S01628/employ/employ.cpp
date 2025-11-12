#include <bits/stdc++.h>
#define mod 998244353

using namespace std;
const int N = 510;

int n, m;
string s;
int a[N];
int flg = true;

int c(int a, int b) {
	//b zhong xuan a ge
	int tmp = a;
	int ans = 1;
	while (a--) {
		ans = ans % mod * (b--) % mod % mod; 
	}
//	cout << ans << endl;
	return ans % mod;
}

inline void SeaWave() {
	cin >> n >> m;
	cin >> s;
	for (int i = 1; i <= n; ++i)
		if(cin >> a[i], s[i - 1] != '1') flg = false;
	if (m == n) {
		if (flg == false) cout << 0 << '\n';
		else {
			long long res = 1;
			int tmp = n;
			for (int i = 1; i <= tmp; ++i)
				res = res % mod * i % mod % mod;
			cout << res % mod << '\n';
			return ;
		}
	} 
//	if (m == 1) {
//		if (flg == )
//		return ;
//	}
	if (flg == true) {
		long long tot = 0;
		for (int i = m; i <= n; ++i)
			tot += c(i, n) % mod;
		cout << tot % mod<< endl;
		return ;
	} 
}

int main() {
	freopen("empoly.in", "r", stdin);
	freopen("empoly.out", "w", stdout);
	int T = 1;
//	T = read();
	while (T--)
		SeaWave();
	return 0;
}
