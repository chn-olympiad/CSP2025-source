#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mo = 998244353;
const int N = 500+3;

char s[N];
int n, m, a[N], p[N], c, v[N], b[N];
ll fac[N], ans;

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);

	scanf("%d%d%s", &n, &m, s+1);
	fac[0] = 1;
	for(int i=1; i <= n; ++i) fac[i] = fac[i-1]*i%mo;
	for(int i=1; i <= n; ++i) cin >> a[i];
	sort(a+1, a+n+1);
	for(int i=1; i <= n; ++i) s[0] += s[i]-'0';
	if(m == 1) {
		int c = 0;
		ans = 1;
		for(int i=1; i <= n; ++i) {
			if(s[i] == '1') {
				int k = lower_bound(a+1, a+n+1, i) - a;
				ans = ans*(k-1-c)%mo, c++;
			}
		}
		ans = (fac[n]-ans*fac[n-c]%mo+mo) % mo;
	}
	else if(m == n) {
		int fl=1;
		for(int i=1; i <= n; ++i) if(a[i] < i || s[i]=='0') fl=0;
		ans = fl ? fac[n] : 0;
	}
	else {
		cerr << "BF\n";
		for(int i=1; i <= n; ++i) b[i]=i;
		do {
			int c = 0;
			for(int i=1; i <= n; ++i) {
				if(c >= a[b[i]] || s[i]=='0') c++;
			}
			ans += n-c >= m;
		} while(next_permutation(b+1, b+n+1));
		ans %= mo;
	}
//	else {
//		for(int i=1; i <= n; ++i) if(s[i]=='1') p[++c] = i;
//		for(int s=0; s<1<<c; ++s) {
//			if(__builtin_popcount(s) < m) continue;
//			for(int i=1; i <= c; ++i) v[i] = s>>i-1&1;
//			
//		}
//	}
	cout << ans;
	return 0;
}

