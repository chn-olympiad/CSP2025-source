#include <iostream>
#include <cstdio>
using namespace std;

long long n, m, s[505], c[505], ans=0, mod=998244353;
int f[505];

void dfs(int step, long long mm, long long ct) {
	if (step > n) {
		if (mm >= m) ans = (ans+1)%mod;
		return;
	}
	
	for (long long i=1; i<=n; i++) {
		if (f[i]>0) continue;
		f[i] = step;
		if (!s[step] || ct >= c[i]) dfs(step+1, mm, ct+1);
		else dfs(step+1, mm+1, ct);
		f[i] = 0;
	}
	
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	scanf("%lld %lld", &n, &m);
	for (long long i=1; i<=n; i++) {
		char c; scanf("%c", &c);
		s[i] = c-'0';
	}
	for (long long i=1; i<=n; i++) {
		scanf("%lld", &c[i]);
	}
	
	dfs(1, 0, 0);
	
	cout << ans;
	
	return 0;
}

