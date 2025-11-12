#include<bits/stdc++.h>
using namespace std;
const int N=2e7+10,M=1e4+10;
int n,m,k,c[M],res[10][M],cnt;
struct node
{
	int u,v;
	long long w;	
};
node r[N];
int p[N];
bool st[M];
int find(int x)
{
	if(x!=p[x])
	{
		p[x]=find(p[x]);
	}
	return p[x];
}
long long ans;
bool cmp(node x,node y)
{
	return x.w<y.w;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		p[i]=i;
	}
	for(int i=1;i<=m;i++)
	{
		cin>>r[i].u>>r[i].v>>r[i].w;
	}
	cnt=m;
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			cin>>res[i][j];
		}
	}
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int x=j+1;x<=n;x++)
			{
				if(k==j)
				{
					continue;
				}
				cnt++;
				r[cnt].u=j,r[cnt].v=x,r[cnt].w=c[i]+res[i][j]+res[i][x];
			}
		}
	}
	sort(r+1,r+cnt+1,cmp);
	for(int i=1;i<=cnt;i++)
	{
		if(find(r[i].u)==find(r[i].v))
		{
			continue;
		}
		ans+=r[i].w;
		p[find(r[i].u)]=find(r[i].v);
	}
	cout<<ans<<endl;
	return 0;
}
