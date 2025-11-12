#include<bits/stdc++.h>
using namespace std;
const int maxn = 505;
const int mod = 998244353;
int n, m;
char s[maxn];
int c[maxn];
bool used[maxn];
long long jc(int x) {
	long long sum = 1;
	for (long long i = 1; i <= x; i++)sum = sum * (i % mod) % mod;
	return sum;
}
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	for (int i = 1; i <= m; i++)cin >> c[i];
	sort(c + 1, c + n + 1);
	if (m == 1) {
		long long ans = 1;
		int t = 0;
		for (int i = 1; i <= n; i++) {
			if (s[i] == '0') {
				t++;
			}
			if (s[i] == '1') {
				cout << ans % mod << '\n';
				return 0;
			}
			for (int j = t; j <= n; j++) {
				if (c[j] <= t)t++;
			}
			ans *= (n - t);
			ans %= mod;
		}
	}
	for(int i=1;i<=n;i++)cout<<c[i]<<" ";
	cout<<'\n';
	int t=0;
	for (int i = 1; i <= n; i++)if (c[i] == 0 || c[i] <= t)t++;
	cout<<n-t;
	if(n-t<m)cout << jc(n-t) << '\n';
	else cout << jc(m) << '\n';
//	int t = 0;
//	long long ans = 1;
//	for (int k = 1; k <= n; k++) {
//		for (int i = 1; i <= n; i++) {
//			if (s[k] == '0' && c[i] == 0)t++;
//			for (int j = 1; j <= n; j++) {
//				if (c[i] <= t && used[i] == 0) {
//					used[i] = 1;
//					t++;
//				}
//			}
//			if (t < m)ans += (ans * (n - t)) % mod;
//			else break;
//		}
//	}
//	cout << ans << '\n';
	return 0;
}