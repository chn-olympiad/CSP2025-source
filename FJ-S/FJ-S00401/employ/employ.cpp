#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N = 1e6 + 10;
const int mod = 998244353;

int n, m;
string str;
int c[N], s[N];
int st[N];
int res = 0;
int Cnt[N];

void dfs(int u)
{
	if(u == n + 1)
	{
		int lose = 0, cnt = 0;
		for(int i = 1 ; i <= n ; i ++ )
			if(c[s[i]] <= lose) lose ++ ;
			else{
				if(str[i - 1] == '0') lose ++ ;
				else cnt ++ ;
			}
		if(cnt >= m) 
		{
			Cnt[s[1]] ++ ;
			res ++ ;
		}
		return;
	}
	for(int i = 1 ; i <= n ; i ++ )
		if(st[i] == false)
		{
			st[i] = true;
			s[u] = i;
			dfs(u + 1);
			st[i] = false;
		}
}
signed main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> str;
	for(int i = 1 ; i <= n ; i ++ ) cin >> c[i];
	bool st = true;
	for(int i = 0 ; i < str.size() ; i ++ )
		if(str[i] == '0')
		{
			st = false;
			break;
		}
	if(st == true)
	{
		int ans = 1;
		for(int i = 1 ; i <= n ; i ++ ) ans = ans * i % mod;
		cout << ans;
		return 0;
	}
	int cnt = 0;
	for(int i = 0 ; i < str.size() ; i ++ )
		if(str[i] == '1')
			cnt ++ ;
	if(cnt < m)
	{
		cout << 0;
		return 0;
	}
	if(m == 1 && n >= 13)
	{
		int op = -1;
		for(int i = 0 ; i < str.size() ; i ++ )
			if(str[i] == '1')
			{
				op = i;
				break;
			}
		int ans = 0;
		for(int i = 1 ; i <= n ; i ++ )
			if(c[i] > op)
				ans ++ ;
		for(int i = 1 ; i < n ; i ++ ) ans = ans * i % mod;
		cout << ans;
		return 0;
	}
	dfs(1);
	cout << res << endl;
	return 0;
}

/*
5 1
11011
6 0 4 2 1

*/
