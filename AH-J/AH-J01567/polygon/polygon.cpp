#include <bits/stdc++.h>
using namespace std;
long long n,a[5005],ans = 0;
bool f[5005] = {false};
void dfs(long long c,long long zcb,long long zcd,long long l)
{
	if (c >= 4 && zcb * 2 < zcd)
	{
		ans++;
		ans %= 998244353;
	}
	for (long long i = l;i <= n;i++)
	{
		if (f[i] == false)
		{
			f[i] = true;
			dfs(c + 1,max(zcb,a[i]),zcd + a[i],i);
			f[i] = false;
		}
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for (long long i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	sort(a + 1,a + n + 1);
	dfs(1,0,0,1);
	cout << ans % 998244353 << endl;
}
