#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 998244353;

int n,m,c[505],a[505],f[505],cnt;
string s;
void dfs(int x)
{
	if (x > n)
	{
		int num = 0;
		for (int i = 1;i <= n;i++)
		{
			if (s[i] == '1' && i-1-num < c[a[i]]) num++;
			if (num > m) return;
		}
		if (num == m) cnt++;
		cnt %= mod;
		return;
	}
	for (int i = 1;i <= n;i++)
	{
		if (f[i] == 1) continue;
		f[i] = 1; 
		a[x] = i;
		dfs(x+1);
		f[i] = 0;
	}
}

signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	cin >> s;
	s = " "+s;
	int flag = 0;
	for (int i = 1;i <= n;i++)
	{
		if (s[i] == '0') flag = 1;
	}
	for (int i = 1;i <= n;i++) cin >> c[i];
	if (flag == 0)
	{
		if (m != n) 
		{
			cout << 0;
			return 0;
		}
		int ans = 1;
		for (int i = 1;i <= n;i++) 
		{
			ans *= i;
			ans %= mod;
		}
		cout << ans;
		return 0;
	}
	if (n <= 18) 
	{
		dfs(1);
		cout << cnt;
		return 0;
	}
	cout << 0;
	
	return 0;
}
