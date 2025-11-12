#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 507, mo = 998244353;
int i, j, k, n, m, t, c[N], p[N];
char s[N];

int main() {	
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%d%d%s", &n, &m, s+1);
	t = n;
	for(i=1; i<=n; i++) scanf("%d", &c[i]), t -= !c[i];
	if(n <= 12) {
//		cout << 1 << "qwq\n";
		for(i=1; i<=n; i++) p[i] = i;
		int ans = 0;
		do {
			int i, k = 0;
			for(i=1; i<=n; i++) {
//				cout << s[i] << " ";
				if(k >= c[p[i]] || s[i]=='0') ++k;
			}
//			cout<<" " << k << "\n";
			if(n - k >= m) ++ans;
			ans %= mo;
		} while(next_permutation(p+1, p+1+n));
		printf("%d\n", ans);
		return 0;
	}
	int flag = 1;
	for(i=1; i<=n; i++) {
		if(s[i] != '1') flag = 0;
	}
	if(flag) {
		ll s = 1;
		for(i=1; i<=t; i++) s = 1ll * s * i % mo;
		printf("%lld\n", s);
		return 0;
	}
	return 0;
} 
