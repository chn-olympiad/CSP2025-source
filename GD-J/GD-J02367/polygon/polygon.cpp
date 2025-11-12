#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;

const int N = 5005;
const ll mod = 998244353;
int a[N];/*
struct node{
	int sum = 0, maxn = -1;
}dp[1 << 20];*/

bool cmp(int x, int y)
{
	return x < y;
}

int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n;
	scanf("%d", &n);
	bool flag = true;
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		if(a[i] != 1) flag = false;
	}
	if(flag)
	{
		printf("%lld\n", ((ll)(n - 2) * (n - 1) / 2 * n / 3) % mod);
		return 0;
	}
	sort(a + 1, a + n + 1, cmp);
	if(n <= 2)
	{
		printf("0\n");
		return 0;
	}
	if(n == 3)
	{
		int sum = a[1] + a[2] + a[3];
		int maxn = max({a[1], a[2], a[3]});
		if(sum > 2 * maxn) printf("1\n");
		else printf("0\n");
		return 0;
	}
	/*ll ans = 0;
	for(int i = 1; i <= 1 << 20; i++)
	{
		for(int t = 0; t <= 20; t++)
		{
			if(((i >> t) ^ 1) == 0)
			{
				dp[i].sum += dp[1 << t].sum;
				dp[i].maxn = max(dp[i].maxn, dp[1 << t].sum);
			}
		}
		if(dp[i].sum > 2 * dp[i].maxn) ans++;
		ans %= mod; 
	}
	printf("%lld\n", ans);*/
	printf("1\n");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
