#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
struct edge
{
	int u,v,w;
}e[N],ee[N];
int fa[N];
int findf(int x)
{
	if(fa[x]==x)return x;
	return fa[x]=findf(fa[x]);
}
bool cmp(edge a,edge b)
{
	return a.w<b.w;
}
int c[15],a[15][10005];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,kk;
	cin>>n>>m>>kk;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		e[i]={u,v,w};
	}
	for(int i=1;i<=kk;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)cin>>a[i][j];
	}
	sort(e+1,e+m+1,cmp);
	long long minn=1e18;
	for(int i=0;i<=(1<<kk)-1;i++)
	{
		int j=i;
		long long ans=0;
		int k=0,zong=n,cnt=0;
		//cout<<i<<"*\n";
		while(j)
		{
			k++;
			if(j&1)
			{
				ans+=c[k];
				if(ans>minn)break;
				zong++;
				for(int ii=1;ii<=n;ii++)
				{
					ee[++cnt]={k+n,ii,a[k][ii]};
					//cout<<a[k][ii]<<endl;
				}
				//cout<<k<<" ";
			}
			j>>=1;
		}
		if(ans>minn)continue;
		sort(ee+1,ee+cnt+1,cmp);
		//for(int j=1;j<=cnt;j++)cout<<ee[j].u<<" "<<ee[j].v<<" "<<ee[j].w<<endl;
		//cout<<endl;
		for(int j=1;j<=n+kk;j++)fa[j]=j;
		int l=1,r=1,tim=0;
		for(int j=1;j<=m+cnt;j++)
		{
			int fx,fy;
			long long ww;
			if(l<=m&&(r>=cnt||ee[r].w>e[l].w))
			{
				fx=findf(e[l].u);
				fy=findf(e[l].v);
				ww=e[l].w;
				//cout<<e[l].u<<" "<<e[l].v<<" "<<e[l].w<<endl;
				l++;
			}
			else
			{
				fx=findf(ee[r].u);
				fy=findf(ee[r].v);
				ww=ee[r].w;
				//cout<<ee[r].u<<" "<<ee[r].v<<" "<<ee[r].w<<endl;
				r++;
			}
			//cout<<fx<<" "<<fy<<endl;
			if(fx!=fy)
			{
				//cout<<uu<<" "<<vv<<" "<<ww<<endl;
				fa[fx]=fy;
				ans+=ww;
				if(ans>minn)break;
				tim++;
				if(tim==zong-1)break;
			}
		}
		minn=min(minn,ans);
	}
	cout<<minn;
	return 0;
}