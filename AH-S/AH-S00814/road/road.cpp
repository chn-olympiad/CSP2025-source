#include<bits/stdc++.h>
using namespace std;
long long n,m,k,c[15][10005],ans,fa[10005],f=1,flag[100005];
struct fun
{
	long long u,v,w;
}a[4000005],tmpp[400005];
bool cmp(fun a,fun b)
{
	return a.w<b.w;
}
long long find(long long w)
{
	if (fa[w]!=w)
	{
		fa[w]=find(fa[w]);
	}
	return fa[w];
}
void work(long long ew)
{
	long long tmp=m;
	for(int i=1;i<=m;i++)
	{
		tmpp[i]=a[i];
	}
	for (int i=1;i<=n;i++)
		{
			for (int j=i+1;j<=n;j++)
			{
				long long mn=1e18;
				for (int kkk=1;kkk<=k;kkk++)
				{
					if (!flag[kkk])
					{
						continue;
					}
					mn=min(mn,c[kkk][i]+c[kkk][j]);
				}			
				m++;
				a[m].u=i;
				a[m].v=j;
				a[m].w=mn;
			}
		}
		sort(a+1,a+1+m,cmp);
		long long tmpans=0;
		for (int i=1;i<=n;i++)
		{
			fa[i]=i;
		}
		for (int i=1;i<=m;i++)
		{
			long long faa=find(a[i].u),fab=find(a[i].v);
			if (faa==fab)
			{
				continue;
			}
			tmpans+=a[i].w;
			fa[faa]=fab;
		}
		ans=min(ans,tmpans+ew);
		m=tmp;
		for(int i=1;i<=m;i++)
		{
			a[i]=tmpp[i];
		}
		return;
}
void dfs(long long w,long long ansc)
{
	if (w>k)
	{
		work(ansc);
		return;
	}
	dfs(w+1,ansc);
	flag[w]=1;
	dfs(w+1,ansc+c[w][0]);
	flag[w]=0;
	return;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for (int i=1;i<=m;i++)
	{
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	for (int i=1;i<=k;i++)
	{
		for (int j=0;j<=n;j++)
		{
			cin>>c[i][j];
			if (c[i][0])
			{
				f=0;
			}
		}
	}
	for (int i=1;i<=n;i++)
	{
		fa[i]=i;
	}
	if (k==0)
	{
		sort(a+1,a+1+m,cmp);
		for (int i=1;i<=m;i++)
		{
			long long faa=find(a[i].u),fab=find(a[i].v);
			if (faa==fab)
			{
				continue;
			}
			ans+=a[i].w;
			fa[faa]=fab;
		}
		cout<<ans;
		return 0;
	}
	if(f==1)
	{
		for (int i=1;i<=n;i++)
		{
			for (int j=i+1;j<=n;j++)
			{
				long long mn=1e18;
				for (int kkk=1;kkk<=k;kkk++)
				{
					mn=min(mn,c[kkk][i]+c[kkk][j]);
				}			
				m++;
				a[m].u=i;
				a[m].v=j;
				a[m].w=mn;
			}
		}
		sort(a+1,a+1+m,cmp);
		for (int i=1;i<=m;i++)
		{
			long long faa=find(a[i].u),fab=find(a[i].v);
			if (faa==fab)
			{
				continue;
			}
			ans+=a[i].w;
			fa[faa]=fab;
		}
		cout<<ans;
		return 0;
	}
	ans=1e18;
	dfs(0,0);
	cout<<ans;
	return 0;
}
