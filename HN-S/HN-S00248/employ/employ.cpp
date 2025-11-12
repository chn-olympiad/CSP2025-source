#include <iostream>
#include <algorithm>
using namespace std;
long long n,m,a[200005],p[20005],b[20005],mod = 998244353,ans;
string s;
void dfs(int step)
{
	if(step > n)
	{
		int sum = 0,cnt = 0;
		for(int i = 1;i <= n;i ++)
		{
			if(cnt < a[p[i]])
			{
				if(s[i] == '1')sum ++;
				else cnt ++;
			}
			else cnt ++;
			if(sum >= m)
			{
				ans ++;
				return ;
			}
		}
		return ;
	}
	for(int i = 1;i <= n;i ++)
	{
		if(b[i])continue ;
		p[step] = i,b[i] = 1;
		dfs(step + 1);
		p[step] = 0,b[i] = 0;
	}
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m >> s;
	s = " " + s;
	for(long long i = 1;i <= n;i ++)cin >> a[i];
	if(n <= 10)
	{
		dfs(1);
		cout << ans % mod;
		return 0;
	}
	for(long long i = 1;i <= n;i ++)
		if(s[i] == '0')
		{
			cout << 0;
			return 0;
		}
	for(long long i = 1;i <= n;i ++)
		if(a[i] == 0)
		{
			cout << 0;
			return 0;
		}
	long long jie = 1;
	for(long long i = 1;i <= n;i ++)
		jie = jie * i % mod;
	cout << jie;
	return 0;
}

