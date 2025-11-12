#include<bits/stdc++.h>
using namespace std;

int n,m,k,fa[10021],cnt,ans,idx,c[11],f[11];
int edge[10021][10021],a[10021][10021];
struct e
{
	int u,v,w,from;
}ee[4000021];
bool cmp(e x,e y)
{
	return x.w<y.w;
}
int find(int x)
{
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
void join(int u,int v,int w,int from)
{
	int p=find(u),q=find(v);
	if(p!=q)
	{
		if(from)
		{
			if(!f[from])
			{
				ans+=w,f[from]=1,idx++;
				fa[p]=q;
			}
			else
			{
				ans=ans+w-c[from],idx++;
				fa[p]=q;
			}
		}
		else ans+=w,idx++,fa[p]=q;
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m>>k;
	memset(a,0x3f,sizeof a);
	memset(edge,0x3f,sizeof edge);
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		edge[u][v]=edge[v][u]=w;
//		ee[++cnt]={u,v,w,0};
//		ee[++cnt]={v,u,w,0};
	}
	for(int i=1;i<=k;i++)
	{
		int w[100001];
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			cin>>w[j];
		}
		for(int j=1;j<=n;j++)
		{
			for(int d=1;d<j;d++)
			{
				a[d][j]=w[d]+c[i]+w[j];
				ee[++cnt]={d,j,w[d]+c[i]+w[j],i};
				ee[++cnt]={j,d,w[d]+c[i]+w[j],i};
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(edge[i][j]!=0x3f3f3f3f)
			{
				if(a[i][j]>edge[i][j])
				{
					ee[++cnt]={i,j,edge[i][j],0};
					ee[++cnt]={j,i,edge[i][j],0};
				}
			}
		}
	}
	for(int i=1;i<=n;i++)fa[i]=i;
	sort(ee+1,ee+cnt+1,cmp); 
//	for(int i=1;i<=cnt;i++)cout<<ee[i].u<<" "<<ee[i].v<<" "<<ee[i].w<<endl;
	for(int i=1;i<=cnt;i++)
	{
		int x=ee[i].u,y=ee[i].v,w=ee[i].w,from=ee[i].from;
		join(x,y,w,from);
		if(idx==n-1)break;
	}
	cout<<ans;
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

*/
