#include <cstdio>

constexpr int MOD = 998244353;

char s[505];
int c[505];
bool vis[505];

int n, m;

unsigned long long fractal(int n) {
	if (n==0) return 1;
	unsigned long long res=1;
	for (int i = 2 ; i <= n ; i ++) {
		res *= i;
		res %= MOD;
	}
	return res;
}


unsigned long long dfs(int p, int g) {
	if (g>=m) {
		return fractal(n-p+1);
	}
	if (n-p+g+1<m) {
		return 0;
	}
	if (p > n) {
		return 0;
	}
	int sum = 0;
	for (int i = 1 ; i <= n ; i++) {
		if (vis[i]) continue;
		if (p-g-1 >= c[i]) {
			vis[i]=true;
			sum += dfs(p+1, g);
			sum %= MOD;
			vis[i]=false;
		} else {
			vis[i]=true;
			sum += dfs(p+1, g+s[p]-'0');
			sum %= MOD;
			vis[i]=false;
		}
	}
	return sum;
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%d%d%s", &n, &m, s+1);
	int nc = 0;
	for (int i = 1 ; i <= n ; i ++) {
		scanf("%d", &c[i]);
		if (c[i] == 0) {
			nc++;
		}
	}
	bool speca=true, cnt1 = 0;
	for (int i = 1 ; i <= n ; i ++) {
		if (s[i]=='0') {
			speca = false;
		}
		cnt1 += s[i]=='1';
	}
	if (m==n && !speca) {
		putchar('0');
		return 0;
	}
	if (m == 1) {
		int leading = 0;
		for (int i = 1 ; i <= n ; i ++) {
			if (s[i]=='0') {
				leading++;
			} else {
				int avail = 0;
				for (int j = 1 ; j <= n ; j ++) {
					if (c[j] > leading) {
						avail ++;
						avail %= MOD;
					}
				}
				printf("%llu", (fractal(leading)*avail)%MOD*fractal(n-leading-1)%MOD);
				return 0;
			}
		}
		putchar('0');
		return 0;
	}
	if (m>n-nc) {
		putchar('0');
		return 0;
	}
	printf("%llu", dfs(1, 0));
	return 0;
}
