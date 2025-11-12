#include<bits/stdc++.h>
using namespace std;
long long fa[2000005],eg[15][10005],repr[15];
struct Edge
{
	int from,to,val;
}edge[2000005],en[2000005];
bool cmp(Edge i,Edge j)
{
	return i.val<j.val;
}
void uni(long long x,long long y)
{
	fa[y]=x;
}
int find(long long x)
{
	if (fa[x]!=x) fa[x]=find(fa[x]);
	return fa[x]; 
}
long long n,m,k;
long long kru(long long n,long long m)
{
	for (int i=1;i<=m;i++)
	{
		en[i].from=edge[i].from;
		en[i].to=edge[i].to;
		en[i].val=edge[i].val;
		
	}
	for (int i=1;i<=n;i++)fa[i]=i;
	sort(en+1,en+m+1,cmp);
	long long link=0,cost=0;
	for (int i=1;i<=m;i++)
	{
		
		long long x=en[i].from,y=en[i].to;
		int xx=find(x),yy=find(y);
		if (xx!=yy)
		{
			uni(xx,yy);
			link++;
			cost+=en[i].val;
		}
		if (link==n-1) break;
	}
	return cost;
}
long long ans=1e18;
void dfs(long long x,long long gai,long long cost,long long len)
{
	if (x==k+1) 
	{
		ans=min(ans,cost+kru(n+gai,m+len));
		return ;
	}
	for (int i=x+1;i<=k+1;i++)
	{
		if (i==k+1) 
		{
			dfs(i,gai,cost,len);
			continue;
		}
		for (int j=1;j<=n;j++)
		{
			edge[m+(++len)].from=n+i;
			edge[m+len].to=j;
			edge[m+len].val=eg[i][j];
		}
		dfs(i,gai+1,cost+repr[i],len);
		len-=n;
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for (int i=1;i<=m;i++)
	{
		cin>>edge[i].from>>edge[i].to>>edge[i].val;
	}
	for (int i=1;i<=k;i++)
	{
		cin>>repr[i];
		for (int j=1;j<=n;j++)
		{
			cin>>eg[i][j];
		}
	}
	int flag=1;
	for(int i=1;i<=k;i++)
	{
		if (repr[i]!=0) flag=0;
	}
	if(flag==0) dfs(0,0,0,0);
	else
	{
		int len=0;
		for (int i=1;i<=k;i++)
		{
			for (int j=1;j<=n;j++)
			{
				edge[m+(++len)].from=n+i;
				edge[m+len].to=j;
				edge[m+len].val=eg[i][j];
			}
		}
		ans=min(ans,kru(n+k,m+len));
	}
	cout<<ans<<endl;
	return 0;
}
