#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int f[100005];
struct o
{
	int u,v,w;
}p[1000006];
int c[1000006],a[15][100005],f1[1000006],cnt,ma[15],mi[15];
int find(int x)
{
	if(f[x]==x)
	{
		return f[x];
	}
	f[x]=find(f[x]);
	return f[x];
}
bool cmp(o l1,o l2)
{
	return l1.w<l2.w; 
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>p[i].u>>p[i].v>>p[i].w;
	}
	sort(p+1,p+1+n,cmp);
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		mi[i]=2e9;
		ma[i]=2e9;
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
			mi[i]=min(a[i][j],mi[i]);
		}
		int suliang=0;
		for(int j=1;j<=n;j++)
		{
			if(a[i][j]==mi[i])
			{
				suliang++;
			}
			else ma[i]=min(a[i][j],ma[i]);
		}
		if(suliang>2) ma[i]=mi[i];
	} 
	for(int i=1;i<=n;i++)
	{
		f[i]=i;
	}
	int ans=0;
	for(int i=1;i<=m;i++)
	{
		int liu=p[i].u,jin=p[i].v;
		int dx=find(liu),dy=find(jin);
		if(dx==dy) continue;
		else
		{
			ans+=p[i].w;
			f[dx]=dy;
			cnt++;
			f1[cnt]=i;
		}
	}
	for(int i=cnt;i>=1;i--)
	{
		int minn=2e9,g,l=f1[i];
		for(int j=1;j<=k;j++)
		{
			if(a[j][p[l].u]+a[j][p[l].v]<minn)
			{
				minn=a[j][p[l].u]+a[j][p[l].v];
				g=j;
			}
		}
		if(minn+c[g]<=p[l].w)
		{
			ans-=p[l].w ;
			ans+=(minn+c[g]);
			c[g]=0;
			mi[g]=0;
			ma[g]=0;
		}
	} 
	cout<<ans;
	return 0;
} 
