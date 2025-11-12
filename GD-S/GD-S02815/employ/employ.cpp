#include<bits/stdc++.h>
using namespace std;
int n,m;
long long ans = 0;
int c[550],p[550];
bool used[550],hard[550];
string h;
bool employ()
{
	int b = 0;
	int g = 0;
	for(int i = 0;i < n;i++)
	{	
		if(b >= p[i])
		{
			b++;
		}
		else if(hard[i])
		{
			g++;
		}
		else
		{
			b++;
		}
		if(g == m)
		{
			return true;
		}
	}
	return false;
}
void dfs(int f)
{
	if(f == n)
	{
		if(employ())
		{
			ans++;
			ans = ans% 998244353;
		}
		return;
	}
	for(int i = 0;i < n;i++)
	{
		if(used[i])
		{
			p[f] = c[i];
			used[i] = false;
			dfs(f+1);
			used[i] = true;
		}
	}
	return;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m >> h;
	for(int r = 0;r < n;r++)
	{
		cin >> c[r];
		used[r] = true;
	}
	for(int i = 0;i < n;i++)
	{
		if(h[i] == '1')
		{
			hard[i] = true;
		}
		else
		{
			hard[i] = false;
		}
	}
	dfs(0);
	cout << ans;
}
