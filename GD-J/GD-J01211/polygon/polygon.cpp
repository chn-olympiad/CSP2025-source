#include <bits/stdc++.h>
using namespace std;
int n;
int a[5007];
const long long Mod = 998244353;
long long total;
int in[5007];
int ans[5007];
long long add(int l, int k)
{
	double ans = 1;
	for(int i = 1; i <= k ; i++)
	{
		ans *= (l - i + 1);
		ans /= i;
	}
	return ans;
}
void dfs(int x,int need,int now)
{
	if(now + ans[x] < need) return ;
	now += a[x];
	if(now > need)
	{
		total ++;
		total %= Mod;
	}
	if(x == 1)
	{
		return ;
	}
	for(int i = x - 1; i >= 1; i--)
	{
		if(in[i] == 0)
		{
			in[i] = 1;
			dfs(i,need,now);
			in[i] = 0;
		}
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d",&a[i]);
	}
	sort(a + 1,a + n + 1);
	for(int i = 1; i <= n; i++)
	{
		ans[i] = ans[i - 1] + a[i];
	}
	if(n >= 500 and a[n] == 1)
	{
		for(int i = 3; i <= n; i++)
		{
			total += 2;
			for(int j = 1; j < i ; j++)
			{
				total += (add(i,j) % Mod);
				total %= Mod;
			}
		}
	}
	else
	{
		for(int i = n ; i >= 3; i--)
		{
			in[i] = 1;
			dfs(i,a[i] * 2,0);
		}
	}
	printf("%lld",total % Mod);
	return 0;
}
