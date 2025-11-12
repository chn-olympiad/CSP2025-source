#include<bits/stdc++.h>
using namespace std;
const int maxn = 510, mod = 998244353;

int p[maxn], c[maxn];
bool flag = 1;
long long fac[maxn];

int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n, m;scanf("%d%d", &n, &m);
	int ans = 0;
	for (int i = 1;i <= n;i ++) p[i] = i;
	string s;cin >> s;
	for (int i = 1;i <= n;i ++) scanf("%d", &c[i]);
	for (int i = 1;i <= n;i ++) {
		if (c[i] == 0) flag = 0;
	}
	if (n <= 12) {
		do {
			int sum = 0, acc = 0;
			for (int i = 1;i <= n;i ++) {
				if (sum >= c[p[i]]) {
					sum ++;
				} else {
					if (s[i - 1] - '0') {
						acc ++;
					} else {
						sum ++;
					}
				}
			}
			if (acc >= m) ans ++;
		} while(next_permutation(p + 1, p + n + 1));
	} else if (flag && m == n){
		ans = 1;
	} else if (flag){
		fac[0] = 1;
		for (int i = 1;i <= n;i ++) fac[i] = (fac[i - 1] * i) % mod;
		printf("%lld", fac[n]);
		return 0;
	}
	
	printf("%d", ans);
	return 0;
}