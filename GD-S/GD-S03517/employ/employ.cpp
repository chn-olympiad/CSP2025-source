#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 5e2 + 5;
const int M = 998244353;
int n, m, ans, a[N], vis[N];
string s;
bool check(vector<int>& v)
{
	int cnt = 0, res = 0;
	for(int i = 0; i < n; i++)
	{
		if(s[i] == '0' || a[v[i]] <= cnt)
			cnt++;
		else
			res++;
	}
	return res >= m;
}
void dfs(vector<int>& v)
{
	if(v.size() == n)
	{
		if(check(v))
		{
			ans++;
			ans %= M;
		}
		return;
	}
	for(int i = 0; i < n; i++)
	{
		if(vis[i]) continue;
		v.push_back(i);
		vis[i] = 1;
		dfs(v);
		vis[i] = 0;
		v.pop_back();
	} 
	return;
}
signed main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m >> s;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	if(n == m)
	{
		bool flag = false;
		for(int i = 1; i <= n; i++)
		{
			if(s[i] == '0')
			{
				flag = true;
				break;
			}
		}
		if(flag) cout << 0 << endl;	
	}
	else
	{
		vector<int> v;
		dfs(v);
		cout << ans <<endl;
	}
	return 0;
}
