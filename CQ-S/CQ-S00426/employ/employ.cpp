#include<bits/stdc++.h>
using namespace std;
constexpr int maxn = 505, mod = 998244353;
int n, m, c[maxn], p[maxn];
char s[maxn];
int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%d%d%s", &n, &m, s + 1);
	for(int i = 1; i <= n; ++i) scanf("%d", &c[i]);
	if(n <= 10)
	{
		for(int i = 1; i <= n; ++i) p[i] = i;
		int tot = 0;
		do
		{
			int cnt = 0, q = 0;
			for(int i = 1; i <= n; ++i)
			{
				if(cnt < c[p[i]] && s[i] == '1') ++q;
				else ++cnt;
			}
			tot += q >= m;
		}while(next_permutation(p + 1, p + 1 + n));
		printf("%d\n", tot);
		return 0;
	}
	long long ans = 1;
	for(int i = 1; i <= n; i++) ans = ans * i % mod;
	printf("%lld\n", ans);
	return 0;
}