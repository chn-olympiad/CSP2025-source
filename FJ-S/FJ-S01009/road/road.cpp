#include <bits/stdc++.h> 
using namespace std;
const int N = 1e4 + 5;
int n,m,k,mi = INT_MAX,s,e;
int u,v,w;
int a[N][N];
bool f[N][N];
void dfs(int x)
{
	if(e == n - 1)
	{
		mi = min(mi,s);
		return;
	}
	for(int i = 1; i <= n;i++)
	{
		if(a[x][i] != 0 && f[x][i] == false)
		{
			s += a[x][i];
			e++;
			f[x][i] = true;
			dfs(i);
			f[x][i] = false;
			e--;
			s -= a[x][i];
		}
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> n >> m >> k;
	for(int i = 1; i <= m;i++)
	{
		cin >> u >> v >> w;
		a[u][v] = w;
		a[v][u] = w;
	}
	int x1;
	bool flag = false;
	for(int i = 1;i <= k;i++)
	{
		cin >> x1;
		if(x1 != 0) flag = true;
		for(int j = 1;j <= n;j++)
		{
			cin >> x1;
			if(x1 != 0) flag = true;
		}
	}
	if(!flag)
	{
		cout << 0;
		return 0;
	}
	for(int i = 1;i <= n;i++)
	{
		dfs(i);
	}
	cout << mi;
	return 0;
}
