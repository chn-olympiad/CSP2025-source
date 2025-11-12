#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
long long n, a[5010], ans;
long long g[5010];
void dfs(long long now, long long mx, long long sum, long long cnt)
{
	if(now == n + 1 and cnt < 3)
		return ;
	if(now == n + 1 and cnt >= 3)
	{
//		cout << cnt << ":";
//		for(int i = 0; i < cnt; i++)
//		{
//			cout << g[i] << " ";
//		}
//		cout << endl;
		if(sum > mx * 2)
			ans = (ans + 1) % mod;
		return ;
	}
	dfs(now + 1, mx, sum, cnt);
//	g[cnt] = now;
	dfs(now + 1, max(a[now], mx), sum + a[now], cnt + 1);	
}
int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	bool flag = 0;
	scanf("%lld", &n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%lld", &a[i]);
		if(a[i] != 1)
			flag = 1;
	}
	sort(a + 1, a + n + 1);
	if(flag == 0)
	{
		for(int i = 3; i <= n; i++)
		{
			long long sum1 = 1, sum2 = 1;
			for(int j = n; j >= n - i + 1; j--)
				sum1 *= j;
			for(int j = 1; j <= i; j++)
				sum2 *= j;
			ans += sum1 / sum2;
			ans %= mod;
		}
		printf("%lld\n", ans % mod);
		return 0;
	}
	dfs(1, -0x3f3f3f3f, 0, 0);
	printf("%lld\n", ans % mod);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
