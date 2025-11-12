#include <bits/stdc++.h>

using namespace std;
const int maxn = 5004;
int n, a[maxn];
const int INF = 0x3f3f3f3f;
const long long MOD = 998244353;
int a_max = -INF;

void solve()
{
	if(a_max == 1)
	{
		long long ll_n = (long long)n;
		long long ans = 1;
		for(int i=1;i<=n;i++)
			ans = ((ans % MOD) * 2) % MOD;
		ans = ans - 1 - ll_n - (ll_n*(ll_n-1))/2;
		ans += MOD;
		ans = ans % MOD;
		printf("%lld\n", ans);
		return;
	}
	if(n <= 30)
	{
		long long ans = 0;
		for(int i=0;i<(1<<n);i++)
		{
			int b = i;
			int cnt = 0;
			while(b)
			{
				cnt += b&1;
				b >>= 1;
			}
			if(cnt < 3) continue;
			b = i;
			int a_s = 0, a_m = -INF;
			// printf("Current: ");
			for(int i=0;i<n;i++)
			{
				if( !((b>>i)&1) ) continue;
				// printf("%d ", a[i]);
				if(a[i] > a_m) a_m = a[i];
				a_s += a[i];
			}
			// printf(", sum=%d, max=%d \n", a_s, a_m);
			if(a_s > 2*a_m) ans++;
			ans = ans % MOD;
		}
		printf("%lld\n", ans);
		return;
	}
	long long ans = 0;
	for(long long i=0;i<(1<<n);i++)
	{
		long long b = i;
		int cnt = 0;
		while(b)
		{
			cnt += b&1;
			b >>= 1;
		}
		if(cnt < 3) continue;
		b = i;
		int a_s = 0, a_m = -INF;
		// printf("Current: ");
		for(int i=0;i<n;i++)
		{
			if( !((b>>i)&1) ) continue;
			// printf("%d ", a[i]);
			if(a[i] > a_m) a_m = a[i];
			a_s += a[i];
		}
		// printf(", sum=%d, max=%d \n", a_s, a_m);
		if(a_s > 2*a_m) ans++;
		ans = ans % MOD;
	}
	printf("%lld\n", ans);
	return;
}

int main()
{
	// freopen("polygon.in", "r", stdin);
	// freopen("polygon.out", "w", stdout);
	//// i am not going to do this. -- colGem 
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%d", &n);
	for(int i=0;i<n;i++)
	{
		scanf("%d", &a[i]);
		if(a[i] > a_max) a_max = a[i];
	}
	solve();
	return 0;
}
 
