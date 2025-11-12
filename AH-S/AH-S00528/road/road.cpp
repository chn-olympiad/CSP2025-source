#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct rd
{
	int u,v,w,used=0;
}r[2000005];
bool cmp(rd a,rd b)
{
	return a.w<b.w;
};
int f[1000005];
int find(int x)
{
	if(f[x]==x)
	{
		return x;
	}
	return f[x]=find(f[x]);
}
int c[11];
bool mk[11];
int a[1000006][11];
//~ int tmp[1001][1001];
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	bool sA=1;
	//~ memset(tmp,0x3f,sizeof(tmp));
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>r[i].u>>r[i].v>>r[i].w;
		//~ tmp[r[i].u][r[i].v]=min(tmp[r[i].u][r[i].v],r[i].w);
		//~ r[i].w=tmp[r[i].u][r[i].v];
		//~ r[i+m].u=r[i].v,r[i+m].v=r[i.u],r[i+m].w=r[i].w;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		if(c[i]!=0)
		{
			sA=0;
		}
		for(int j=1;j<=n;j++)
		{
			cin>>a[j][i];
		}
	}
	if(sA)
	{
		int sum=0,tot=0;
		for(int i=1;i<=n;i++)
		{
			f[i]=i;
		}
		sort(r+1,r+m+1,cmp);
		//~ for(int i=1;i<=m;i++)
		//~ {
			//~ cout<<r[i].u<<" "<<r[i].v<<" "<<r[i].w<<"\n";
		//~ }
		for(int i=1ll;i<=m&&tot<n-1;i++)
		{
			int u=find(r[i].u),v=find(r[i].v);
			if(u!=v)
			{
				//~ cout<<r[i].u<<" "<<r[i].v<<" "<<r[i].w<<"\n";
				r[i].used=1;
				f[u]=v;
				tot++;
				sum+=r[i].w;
			}
			//~ else
			//~ {
				//~ cout<<"!!!";
				//~ return 0;
				//~ cout<<u<<" "<<v<<"\n";
			//~ }
		}
		for(int i=1;i<=m;i++)
		{
			if(r[i].used==1)
			{
				for(int j=1;j<=k;j++)
				{
					if(a[r[i].u][j]+a[r[i].v][j]<r[i].w)
					{
						sum=sum-r[i].w+a[r[i].u][j]+a[r[i].v][j];
					}
				}
			}
		}
		cout<<sum<<"\n";
	}
	return 0;
}
//拼尽全力无法战胜...
