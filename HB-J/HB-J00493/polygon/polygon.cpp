#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int n, a[5005], s[5005], cnt;
void dfs(int s, int sum, int maxn)
{
	if(s > n)
	{
		if(sum > maxn * 2)
		{
			cnt++;
			cnt %= mod;
		}
		return;
	}
	dfs(s + 1, sum, maxn);
	int t = s, p = max(maxn, a[t]), tm = maxn;
	dfs(s + 1, sum + a[t], p);
	maxn = tm;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n ;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i] ;
	}
	dfs(1, 0, 0);
	cout << cnt % mod ;
	return 0;
}
