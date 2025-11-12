#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod 998244353

int read() {
	int x = 0, f = 1;
	char c = getchar();
	while(!isdigit(c)) {
		if(c == '-') f = -1;
		c = getchar();
	}
	while(isdigit(c)) {
		x = x * 10 + c - '0';
		c = getchar();
	}
	return x * f;
}

signed main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n = read(), m = read();
	string s;
	cin >> s;
	s = ' ' + s;
	vector <int> a(n + 10), f(n + 10);
	for(int i = 1;i <= n;i++) cin >> a[i];
	if(n <= 10) {
		for(int i = 1;i <= n;i++) f[i] = i;
		int ans = 0;
		do {
			int cnt = 0;
			for(int i = 1;i <= n;i++) {
	//			cout << f[i] << " ";
				if(cnt >= a[f[i]]) {
					cnt++;
					continue;
				}
				if(s[i] == '0') cnt++;
				continue;
			}
			if(n - cnt >= m) ans++;
			ans %= mod;
	//		cout << ans << "\n";
		} while(next_permutation(f.begin() + 1, f.begin() + n + 1));
		cout << ans << "\n";
		return 0;
	}
	cout << 0 << "\n";
	return 0;
}
