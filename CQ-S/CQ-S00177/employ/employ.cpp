#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans=0;
char a[1000005];
int b[1000005];
int c[1000005];
int f[1000005];
void dfs(int x)
{
	if (x==n+1)
	{
		int s=0,k=0;
		for (int i=1;i<=n;i++)
		{
			if (k>=b[c[i]])
			{
				k++;
				continue;
			}
			if (a[i]=='1')
				s++;
			else
				k++;
		}
		if (s>=m)
			ans++;
		return;
	}
	for (int i=1;i<=n;i++)
	{
		if (f[i]==0)
		{
			f[i]=1;
			c[x]=i;
			dfs(x+1);
			f[i]=0;
		}
	}
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	for (int i=1;i<=n;i++)
		cin>>b[i];
	dfs(1);
	cout<<ans;
	return 0;
}

