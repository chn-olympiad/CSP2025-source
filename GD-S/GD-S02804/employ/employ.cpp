#include<bits/stdc++.h>
using namespace std;

const int N = 505, MOD = 998244353;

int n, m;
long long ans;
int s[N], c[N], res[N];
bitset<N> bs;
void dfs(int x) {
	int i;
	
	if (x == n + 1) {
		int sn = 0, fn = 0;
		for (i = 1; i <= n; ++i) {
			if (fn < c[res[i]] && s[i]) ++sn;
			else ++fn;
		}
		
		if (sn >= m) ans = (ans + 1) % MOD;
		
		return;
	}
	
	for (i = 1; i <= n; ++i) {
		if (!bs.test(i)) {
			bs.set(i);
			res[x] = i;
			dfs(x + 1);
			bs.reset(i);
		}
	}
}

int main() {
	int i, j;
	
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	scanf("%d%d", &n, &m);
	
	string str;
	
	cin >> str;
	
	for (i = 0; i < str.size(); ++i) s[i + 1] = str[i] - '0';
	
	for (i = 1; i <= n; ++i) scanf("%d", &c[i]);
	
	if (n < 12) {
		dfs(1);
		printf("%lld", ans);
	}
	else {
		if (m == 1) {
			ans = 1;
			for (i = 1; i <= n; ++i) {
				if (s[i]) {
					for (j = 2; j <= n; ++j) ans = (ans * j) % MOD;
				}
			}
			
			printf("%lld", ans);
		}
		else printf("0");
	}

	return 0;
}

