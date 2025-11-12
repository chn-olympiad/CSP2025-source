#include<bits/stdc++.h>
using namespace std;
int c[15],a[15][10005],cnt[10005];
struct node{
	int u,v,w;
}r[1000005];
bool cmp(node a,node b)
{
	return a.w<b.w;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,t,ans=0;
	bool f;
	cin>>n>>m>>k;
	for (int i=1;i<=m;++i)
	{
		cin>>r[i].u>>r[i].v>>r[i].w;
	}
	for (int i=1;i<=k;++i)
	{
		cin>>c[i];
		for (int j=1;j<=n;++j)
		{
			cin>>a[i][j];
		}
	}
	sort(r+1,r+m+1,cmp);
	for (int i=1;i<=m;++i)
	{
		ans+=r[i].w;
		++cnt[r[i].u];
		++cnt[r[i].v];
		f=1;
		for (int j=1;j<=n;++j)
		{
			if (cnt[j]==0)
			{
				goto here;
			}
			if (cnt[j]>1)
			{
				f=0;
			}
		}
		if (f==0)
		{
			cout<<ans;
			return 0;
		}
		here:;
	}
	return 0;
}
