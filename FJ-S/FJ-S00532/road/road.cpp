#include<iostream>
#include<algorithm>
#include<vector>
#define int long long
using namespace std;
int n,m,k;
struct Edge
{
	int u,v,w;
}e[1000005];
int fa[1005],c[1005],a[1005][1005],tong[10005];
bool flag[10005];
vector<int>path[2005];
int find(int x)
{
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
bool Union(int u,int v)
{
	u=find(u),v=find(v);
	if(u==v)return 0;
	fa[u]=v;
	return 1;
}
bool cmp(Edge a,Edge b)
{
	return a.w<b.w;
 } 
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n+k;i++)
	{
		fa[i]=i;
	}
	for(int i=1;i<=m;i++)
	{
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	if(k==0)
	{
		int ans=0,cnt=0;
		sort(e+1,e+m+1,cmp);
		for(int i=1;i<=m;i++)
		{
			if(Union(e[i].u,e[i].v))
			{
				ans+=e[i].w;
				cnt++;
				if(cnt==n-1)break;
			}
		}
		cout<<ans;
		return 0;
	}
	int cnt=m;
	for(int i=1;i<=n;i++)
	{
		e[++cnt]=(Edge){0,i,0};
	}
	bool f1=0,f2=0;
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		e[++cnt]=(Edge){0,n+i,c[i]};
		if(c[i])f1=1;
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
			if(a[i][j])f2=1;
			e[++cnt]=(Edge){n+i,j,a[i][j]};
		}
	}
	if(!f1&&!f2)
	{
		cout<<0;
		return 0;
	}
//	for(int i=1;i<=cnt;i++)
//	{
//		cout<<e[i].u<<" "<<e[i].v<<" "<<e[i].w<<"\n";
//	}
	int ans=0,cntb=0;
	for(int i=1;i<=cnt;i++)
	{
		if(Union(e[i].u,e[i].v))
		{
			ans+=e[i].w;
			cntb++;
		}
	}
	cout<<ans;
	return 0;
 } 
