#include<bits/stdc++.h>
using namespace std;

const int mod=998244353;
int n,m,c[505],cnt,fact[505];
bool a[505],used[505];
inline void dfs(int t,int u)
{
	if (u>=m)
		cnt++;
	if (t-u>m || t>n) return;
	for (int i=1;i<=n;i++)
	{
		if (!used[i])
		{
			used[i]=1;
			if (t-u>=c[i] || a[t]==0)
				dfs(t+1,u);
			else
				dfs(t+1,u+1);
			used[i]=0;
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	char tmp;
	for (int i=1;i<=n;i++)
	{
		cin >> tmp;
		a[i]=tmp-'0';	
	}
	for (int i=1;i<=n;i++)
		cin >> c[i];
	dfs(1,0);
	cout << cnt;
	return 0;
}
