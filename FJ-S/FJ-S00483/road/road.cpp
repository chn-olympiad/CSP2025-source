#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,f[10010],ans,w;
struct Node
{
	int x,y,w;
} a[2000010];
bool cmp(Node a,Node b)
{
	return a.w<b.w;
}
int find(int x)
{
	if(f[x]==x)
	{
		return f[x];
	}
	return f[x]=find(f[x]);
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1; i<=m; i++)
	{
		cin>>a[i].x>>a[i].y>>a[i].w;
	}
	for(int i=1; i<=n; i++)
	{
		f[i]=i;
	}
	if(k==0)
	{
		sort(a+1,a+m+1,cmp);
		for(int i=1; i<=m; i++)
		{
			if(w==n-1)
			{
				break;
			}
			int x=find(a[i].x);
			int y=find(a[i].y);
			if(x==y)
			{
				continue;
			}
			f[x]=y;
			ans+=a[i].w;
			w++;
		}
		cout<<ans;
	}
	else
	{
		for(int i=1;i<=k;i++)
		{
			f[n+i]=n+i;
		}
		for(int i=1; i<=k; i++)
		{
			int x;
			cin>>x;
			for(int j=1; j<=n; j++)
			{
				int y;
				cin>>y;
				a[++m].x=i+n;
				a[m].y=j;
				a[m].w=y;
			}
		}
		sort(a+1,a+m+1,cmp);
		for(int i=1; i<=m; i++)
		{
			if(i>=n-1)
			{
				int flg=1;
				for(int j=1; j<=n-1; j++)
				{
					if(find(j)!=find(j+1))
					{
						flg=0;
					}
				}
				if(flg)
				{
					break;
				}
			}
			int x=find(a[i].x);
			int y=find(a[i].y);
			if(x==y)
			{
				continue;
			}
			f[x]=y;
			ans+=a[i].w;
		}
		cout<<ans<<"\n";
	}
	return 0;
}

