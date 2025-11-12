#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n,maxx=-1;
int a[1000005][10];
int b[1000005];
int f[10];
void dfs(int x)
{
	if (x==n+1)
	{
		for (int i=1;i<=3;i++)
			f[i]=0;
		for (int i=1;i<=n;i++)
			f[b[i]]++;
		for (int i=1;i<=3;i++)
		{
			if (f[i]>n/2)
				return;
		}
		int ans=0;
		for (int i=1;i<=n;i++)
			ans+=a[i][b[i]];
		maxx=max(maxx,ans);
		return;
	}
	for (int i=1;i<=3;i++)
	{
		b[x]=i;
		dfs(x+1);
	}
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while (t--)
	{
		maxx=-1;
		cin>>n;
		for (int i=1;i<=n;i++)
			for (int j=1;j<=3;j++)
				cin>>a[i][j];
		dfs(1);
		cout<<maxx<<'\n';
	}
	return 0;
}

