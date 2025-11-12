#include <bits/stdc++.h>
using namespace std;
bool f[100005];
int c[100005],n,m,ans,sn[100005],nm,fa;
string s;
void dfs(int x)
{
	if (x>n)
	{
		if (nm>=m)
		{
			ans++;
		}
		return ;
	}
	for (int i=1;i<=n;i++)
	{
		if (f[i]==0)
		{
			f[i]=1;
			if (sn[x]==1&&fa<c[i])
			{
				nm++;
				dfs(x+1);
				nm--;
				f[i]=0;
				continue;
			}
			else if (sn[x]==0&&fa<c[i])
			{
				fa++;
				dfs(x+1);
				fa--;
				f[i]=0;
				continue;
			}
			else
			{
				dfs(x+1);
				f[i]=0;
				continue;
			}
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	cin >> s;
	for (int i=1;i<=n;i++)
	{
		cin >> c[i];
	}
	for (int i=1;i<=n;i++)
	{
		if (s[i-1]=='1')
		{
			sn[i]=1;
		}
	}
	dfs(1);
	cout << ans;
	return 0;
}
