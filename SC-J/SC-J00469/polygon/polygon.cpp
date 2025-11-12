#include <cstdio>
#include <algorithm>
const int N = 5005;
typedef long long ll;
const ll Q = 998244353;
ll qpow2[N];
int n;
int l[N];
ll f[N][N];
ll ans;
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &l[i]);
	qpow2[0] = 1;
	for(int i = 1; i <= n; i++) qpow2[i] = qpow2[i - 1] * 2 % Q;
	std::sort(l + 1, l + n + 1);
	int m = 5000;
	f[0][0] = 1;
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j <= m; j++) {
			f[i][j] = f[i - 1][j];
			if(j >= l[i]) f[i][j] += f[i - 1][j - l[i]];
			f[i][j] %= Q;
		}
	}
	for(int i = 1; i <= n; ) {
		int t = i;
		while(t < n && l[t + 1] == l[t]) t++;
		ll tans = (qpow2[t] - qpow2[i - 1] + Q) % Q;
		ll cnt = t - i + 1;
		for(int j = 0; j <= l[i]; j++) {
			tans = (tans - f[i - 1][j] * cnt % Q + Q) % Q;
		}
		if(t != i) {
			tans = (tans - cnt * (cnt - 1) / 2 % Q + Q) % Q; 
		}
		ans = (tans + ans) % Q;
		i = t + 1;
	}
	printf("%lld\n", (ans % Q + Q) % Q);
	fclose(stdin);
	fclose(stdout);
	return 0;
}