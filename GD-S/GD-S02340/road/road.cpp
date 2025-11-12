#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
typedef long long ll;
struct node
{
	ll v,w;
};
const int N=1e4+6;
vector<node> r[N];
bool vis[N],vis1[15];
ll n,m,k;
ll p[15][N];
ll minn=0x3f3f3f3f;
bool check()
{
	for(int i=1;i<=n;i++)
	{
		if(vis[i]==0)
			return false;
	}
	return true;
}
void fk0(ll pos,ll cost)
{
	if(check())
	{
		minn=min(minn,cost);
		return;
	}
	for(int i=0;i<r[pos].size();i++)
	{
		if(vis[r[pos][i].v]==0)
		{
			vis[r[pos][i].v]=1;
			fk0(r[pos][i].v,cost+r[pos][i].w);
			vis[r[pos][i].v]=0;
		}
	}
	return;
}
void f0(ll pos,ll cost,ll uk)
{
	if(check())
	{
		minn=min(minn,cost);
		return;
	}
	for(int i=0;i<r[pos].size();i++)
	{
		if(vis[r[pos][i].v]==0)
		{
			vis[r[pos][i].v]=1;
			f0(r[pos][i].v,cost+r[pos][i].w,uk);
			if(uk<k) f0(r[pos][i].v,cost,uk+1);
			vis[r[pos][i].v]=0;
		}
	}
	return;
}
void f(ll pos,ll cost)
{
	if(check())
	{
		minn=min(minn,cost);
		return;
	}
	for(int i=0;i<r[pos].size();i++)
	{
		if(vis[r[pos][i].v]==0)
		{
			vis[r[pos][i].v]=1;
			f(r[pos][i].v,cost+r[pos][i].w);
			for(int j=1;j<=m;j++)
			{
				if(vis1[j]==0)
				{
					vis1[j]=1;
					f(r[pos][i].v,cost+p[j][0]+p[j][pos]+p[j][r[pos][i].v]);
					vis1[j]=0;
				}
			}
			vis[r[pos][i].v]=0;
		}
	}
	return;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		r[u].push_back({v,w});
		r[v].push_back({u,w});
	}
	bool flag=1;
	for(int i=1;i<=k;i++)
	{
		for(int j=0;j<=n;j++)
		{
			cin>>p[i][j];
			if(p[i][j]!=0)
				flag=0;
		}
	}
	if(k==0)
	{
		for(int i=1;i<=n;i++)
		{
			vis[i]=1;
			fk0(i,0);
			vis[i]=0;
		}
	}
	else if(flag)
	{
		for(int i=1;i<=n;i++)
		{
			vis[i]=1;
			f0(i,0,0);
			vis[i]=0;
		}
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			vis[i]=1;
			f(i,0);
			vis[i]=0;
		}
	}
	cout<<minn;
	// how wonderful the Formula 1 is!
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

