#include <bits/stdc++.h>
using namespace std;
#define int long long
struct edge
{
	int x,y,z;
}e[1145141];
bool cmp(edge a,edge b)
{
	return a.z<b.z;
}
int f[1145141];
int a[1145141],b[15][11451];
int find(int x)
{
	if(f[x]==x)return x;
	return f[x]=find(f[x]);
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=m;i++)cin>>e[i].x>>e[i].y>>e[i].z;
	sort(e+1,e+1+m,cmp);
	if(k==0)
	{
		int ans=0;
		for(int i=1;i<=m;i++)
		{
			int x=e[i].x,y=e[i].y;
			int fx=find(x),fy=find(y);
			if(fx!=fy)
			{
				f[fx]=fy;
				ans+=e[i].z;
			}
		}
		cout<<ans<<'\n';
	}
	else
	{
		bool flag=1;
		int tot=m;
		for(int i=1;i<=k;i++)
		{
			cin>>a[i];
			if(a[i])flag=0;
			for(int j=1;j<=n;j++)cin>>b[i][j];
		}
		if(flag)
		{
			int ans=0;
			int t=0;
			for(int i=1;i<=k;i++)
			{
				for(int j=1;j<=n;j++)if(!b[i][j])t=j;
				for(int j=1;j<=n;j++)
				{
					if(j==t)continue;
					if(!b[i][j])f[find(j)]=find(t);
					else e[++tot].x=j,e[tot].y=t,e[tot].z=b[i][j];
				}
			}
			sort(e+1,e+1+tot,cmp);
			for(int i=1;i<=m;i++)
			{
				int fx=find(e[i].x),fy=find(e[i].y);
				if(fx!=fy)
				{
					f[fx]=fy;
					ans+=e[i].z;
				}
			}
			cout<<ans<<'\n';
		}
		else
		{
			int ans=0;
			for(int i=1;i<=m;i++)
			{
				int x=e[i].x,y=e[i].y;
				int fx=find(x),fy=find(y);
				if(fx!=fy)
				{
					f[fx]=fy;
					ans+=e[i].z;
				}
			}
			cout<<ans<<'\n';
		}
	}
	return 0;
}
