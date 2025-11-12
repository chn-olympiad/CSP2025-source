#include <iostream>
#include <cstring>
#include <algorithm>
#define mod 998244353
using namespace std;
int n, ans, maxnn, summ, aans;
int a[5005];
int vis[5005];
void solve(int now, int len, int nl, int maxn, int sum)//nl = 当前选了多少个木棍 
{
	if(vis[now])
	{
		return;
	}
	vis[now] = 1;
	nl++;
	sum += a[now];
	if(a[now] > maxn)
	{
		maxn = a[now];
	}
	if(nl == len && sum > 2 * maxn)
	{
		ans++;
		ans %= mod;
		//cout << ans << "ans now" << now << " len" << len << " nl" << nl << "\n";
	}
	if(nl == len)
	{
		return;
	}
	for(int i = 1; i <= n; i++)
	{
		memset(vis, 0, n);
		solve(i, len, nl, maxn, sum);
		
	}
}
void baoli(int now)
{
	now++;
	if(summ > 2 * maxnn)
	{
		aans++;
		ans %= mod;
	}
	if(now == n)
	{
		return;
	}
	for(int i = now + 1; i <= n; i++)
	{
		summ += a[i];
		maxnn = max(maxnn, a[i]);
		baoli(i);
	}
}
int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	if(n < 3)
	{
		cout << "0";
		return 0;
	}
	if(n == 3)
	{
		cout << a[1] << " " << a[2] << " " << a[3];
		return 0;
	}
	if(n <= 9)
	{
		baoli(1);
		cout << aans;
		return 0;
	}
//	for(int len = 3; len <= n; len++)
//	{
//		for(int i = 1; i <= n; i++)
//		{
//			memset(vis, 0, n);
//			maxn = 0, sum = 0;
//			solve(i, len, 0);
//		}
//	}
	for(int i = 1; i <= n; i++)
	{
		for(int len = 3; len <= n; len++)
		{
			//memset(vis, 0, n);
			solve(i, len, 0, 0, 0);
			//cout << "Yes\n";
		}
	}
	cout << ans % mod * 2;
	return 0;
}
