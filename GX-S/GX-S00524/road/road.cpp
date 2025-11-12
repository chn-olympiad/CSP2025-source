#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2000009;
struct ed
{
	int u,v,w;
}ep[N];

int vis[10001];
int n,m,k;
int c[100];
int ans=0;
int tot;
int x,y,z;
int fa[10001];
bool cmd(ed a,ed b)
{
	return a.w<b.w;
}
void solve()
{
	int p=1;
	int g=1;
	while(p<=tot)
	{
		x=ep[g].u,y=ep[g].v,z=ep[g].w;
		//cout<<x<<" "<<y<<" "<<fa[x]<<" "<<fa[y]<<endl;
		while(fa[fa[x]]!=fa[x])
		{
			fa[x]=fa[fa[x]];
		}
		while(fa[fa[y]]!=fa[y])
		{
			fa[y]=fa[fa[y]];
		}
		if(fa[x]==fa[y])
		{
			g+=1;
			continue;
		}
		fa[x]=y;
		while(fa[fa[x]]!=fa[x])
		{
			fa[x]=fa[fa[x]];
		}
		p+=1;
		g+=1;
		ans+=z;
		//cout<<x<<" "<<y<<endl;
	}
	return;
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		fa[i]=i;
	}
	for(int i=1;i<=m;i++)
	{
		cin>>ep[i].u>>ep[i].v>>ep[i].w;
		int pi=0;
		if(ep[i].u>ep[i].v)
		{
			pi=ep[i].u;
			ep[i].u=ep[i].v;
			ep[i].v=pi;
		}
	}
	for(int i=1;i<=k;i++)
	{
		int name=n+i;
		int cost;
		int pd;
		cin>>cost;
		for(int i=1;i<=n;i++)
		{
			cin>>pd;
			m+=1;
			ep[m].u=i;
			ep[m].v=name;
			ep[m].w=cost+pd;
		}
	}

	sort(ep+1,ep+1+m,cmd);
	tot=n+k-1;
	solve();
	cout<<ans<<endl;
	return 0;
}
