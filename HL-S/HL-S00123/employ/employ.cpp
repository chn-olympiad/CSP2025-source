#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 998244353;
int n,m,c[510];
string s;
int a[510],vis[510],ans = 0;
void dfs(int dep)
{
	if(dep == n+1)
	{
		int lu = 0,res = 0;
		for(int i = 1;i <= n;i++)
		{
			if(s[i] == '0') res++;
			else
			{
				if(res >= c[a[i]]) res++;
				else lu++;
			}
		}
		if(lu >= m) 
		{
//			for(int i = 1;i <= n;i++)
//				cout << a[i] << " ";
//			cout << endl;
			ans++;
//			return;
		}
		return;
	}
	for(int i = 1;i <= n;i++)
	{
		if(vis[i]) continue;
		a[dep] = i;
		vis[i] = 1;
		dfs(dep+1);
		vis[i] = 0;
	}
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0); 
	cin >> n >> m >> s; s = " " + s;
	bool flagA = 1; int gvp = 0;
	for(int i = 1;i <= n;i++)
		if(s[i] != '1') flagA = 0;
	for(int i = 1;i <= n;i++)
	{
		cin >> c[i];
		if(c[i] == 0) gvp++;
	}
	dfs(1);
	cout << ans;
	return 0;
}

