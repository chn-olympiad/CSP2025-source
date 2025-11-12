#include <bits/stdc++.h>
using namespace std;

int c[505];
const long long MOD = 998244353;
long long ans = 0;
int a[505];
int n, m;
string s;
bool flag[505];

bool check(string s)
{
	for(int i = 0; i < s.size(); i++) if(s[i] == '0')	return false;
	return true;
}
void dfs(int step)
{
	if(step > n)
	{
		int cnt = 0;
		int cnt1 = 0;
		for(int i = 1; i <= n; i++)
		{
			if(s[i] == '0')	cnt++;
			else
			{
				if(cnt >= c[a[i]]) cnt++;
				else cnt1++;
			}
		}
		if(cnt1 >= m)	ans++;
		ans %= MOD;
	}
	for(int i = 1; i <= n; i++)
	{
		if(!flag[i])
		{
			flag[i] = 1;
			a[step] = i;
			dfs(step + 1);
			flag[i] = 0;
		}
	}
}
int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	for(int i = 1; i <= n; i++)	cin >> c[i];
	if(m == n)
	{
		bool flag = 0;
		for(int i = 0; i < s.size(); i++) if(s[i] == '1')	flag = 1;
		if(flag)
		{
			long long mul = 1;
			for(int i = 1; i <= n; i++) mul *= i, mul %= MOD;
			cout << mul << endl;
		}	
		else
		{
			cout << 0 << endl;
		}
	}
	else if(m == 1)
	{
		if(check(s))
		{
			long long mul = 1;
			for(int i = 1; i <= n; i++) mul *= i, mul %= MOD;
			cout << mul << endl;
		}
		else
		{
			cout << 0 << endl;
		}
	}
	else if(check(s))
	{
		long long mul = 1;
		for(int i = 1; i <= n; i++) mul *= i, mul %= MOD;
		cout << mul << endl;
	}
	else
	{
		s = " " + s;
		dfs(1);
		cout << ans << endl;
	}
	return 0;
}
