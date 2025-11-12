#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 5010;
const int mod = 998244353;
int n,a[maxn],vis[maxn];
int cnt1 = 0;
void dfs(int dep)
{
	if(dep == n+1)
	{
		int sum = 0,mx = 0;
		for(int i = 1;i <= n;i++)
			if(vis[i]) sum += a[i],mx = max(mx,a[i]);
		if(sum > 2 * mx) cnt1++;
		return;
	}
	vis[dep] = 1;
	dfs(dep+1);
	vis[dep] = 0;
	dfs(dep+1);
}
int pw[50010];
void Bmuli(int a[],int b)
{
	int len = a[0];
	for(int i = 1;i <= len;i++)
	{
		a[i] = a[i] * b;
	}
	for(int i = 1;i <= len;i++)
	{
		if(a[i] >= 10)
		{
			a[i+1] += a[i] / 10;
			a[i] %= 10;
		}
	}
	if(a[len+1] != 0) len++;
	a[0] = len;
}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n; bool flag = 1;
	for(int i = 1;i <= n;i++)
		cin >> a[i],flag &= a[i];
	if(n <= 20)
	{
		dfs(1);
		cout << cnt1 % mod;
		return 0;
	}
	if(flag)
	{
		pw[0] = 1; pw[1] = 2;
		for(int i = 2;i <= n;i++)
			Bmuli(pw,2);
		int ans2 = 0;
		for(int i = pw[0];i >= 1;i--)
		{
			ans2 = (ans2) * 10 + pw[i];
			ans2 %= mod;
		}
		ans2 -= 1;
		ans2 -= n;
		ans2 -= (n-1)*n/2;
		if(ans2 < 0) ans2 += mod;
		ans2 %= mod;
		cout << ans2 << endl;
		return 0;
	}
	return 0;
}

