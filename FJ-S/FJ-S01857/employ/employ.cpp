#include <bits/stdc++.h>

#define MAX_N (500)
#define MOD (998244353) 

int n, m, s[MAX_N + 1], a[MAX_N + 1];

main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout); 

	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%1d", &s[i]);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	
	if (n == m) {
		int flag = 1;
		for (int i = 1; i <= n; i++) flag &= !!a[i];
		for (int i = 1; i <= n; i++) flag &= s[i];
		
		if (!flag) return puts("0"), 0;
		
		long long ans = 1;
		for (int i = 2; i <= n; i++) (ans *= i) %= MOD;
		return printf("%lld\n", ans), 0;
	}

	return 0;	
}
