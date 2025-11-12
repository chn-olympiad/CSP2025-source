#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e4+7;
int n,m,k,ans;
int c[100],b[100][N],fa[N];
bool vis[N];
struct edge
{
	int u,v,w;
}G[N*100];
bool cmp(edge x,edge y)
{
	return x.v<y.v;
}
int find(int x)
{
	while(x!=fa[x])x=fa[x];
	return x;
}
int main(void)
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++)cin>>G[i].u>>G[i].w>>G[i].v;
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			cin>>b[i][j];
		}
	}
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int h=j+1;h<=n;h++)
			{
				G[++m].w=j,G[m].u=h,G[m].v=b[i][j]+b[i][h];
			}
		} 
	}
	sort(G+1,G+1+m,cmp);
	for(int i=1;i<=m;i++)cout<<G[i].w<<' '<<G[i].u<<' '<<G[i].v<<endl;
	if(k==0)
	{
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			int x=G[i].u,y=G[i].w,z=G[i].v;
			if(find(x)!=find(y))
			{
				fa[find(x)]=find(y);
				ans+=z;
				cnt++;
				if(cnt==n-1)
				{
					cout<<ans;
					return 0;
				}
			}
		}	
	}
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		int x=G[i].u,y=G[i].w,z=G[i].v;
		if(find(x)!=find(y))
		{
			fa[find(x)]=find(y);
			ans+=z;
			cnt++;
			if(cnt==n-1)
			{
				cout<<ans;
				return 0;
			}
		}
	}
	return 0;
} 
/*
4 4 1 
1 2 4
2 3 1
3 4 10
1 4 7
0 1 1 1 1
*/
