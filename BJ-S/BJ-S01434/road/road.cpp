#include<bits/stdc++.h>
using namespace std;
struct node
{
	int u,v,w;
}a[10000005];
int f[1005005];
bool cmp(node x,node y)
{
	return x.w<y.w;
}
int find(int x)
{
	if(f[x]==x)return x;
	return f[x]=find(f[x]);
}
void merge(int x,int y)
{
	f[find(x)]=find(y);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	if(k==0)
	{
		for(int i=1;i<=n;i++)
		{
			f[i]=i;
		}
		for(int i=1;i<=m;i++)
		{
			cin>>a[i].u>>a[i].v>>a[i].w;
		}
		sort(a+1,a+m+1,cmp);

		int ans=0;
		for(int i=1;i<=m;i++)
		{
			if(find(a[i].u)!=find(a[i].v))
			{
				merge(a[i].u,a[i].v);
				ans+=a[i].w;
			}
		}
		cout<<ans<<endl;

	}
	else
	{
		int cnt=0;
		for(int i=1;i<=n+k;i++)
		{
			f[i]=i;
		}
		for(int i=1;i<=m;i++)
		{
			cin>>a[i].u>>a[i].v>>a[i].w;
		}
		for(int i=1;i<=k;i++)
		{
			int o;
			cin>>o;
			for(int j=1;j<=n;j++)
			{
				int x;
				cin>>x;
				a[++cnt].u=n+i;
				a[cnt].v=j;
				a[cnt].w=x;
			}
		}
		sort(a+1,a+m+cnt+1,cmp);
		int ans=0;
		for(int i=1;i<=m+cnt;i++)
		{
			if(find(a[i].u)!=find(a[i].v))
			{
				merge(a[i].u,a[i].v);
				ans+=a[i].w;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}