#include <bits/stdc++.h>
using namespace std;
struct node
{
	int v,l;
};
vector<node> g[10005];
struct node2
{
	int u,v,l;
};
bool operator <(node2 a,node2 b)
{
	return a.l>b.l;
}
priority_queue<node2> q;
int f[10015],c[100],a[11][10005];
//bool use[11][10005],vis[10005];
int fr(int x)
{
	return f[x]==x?x:f[x]=fr(f[x]);
}
void add(int a,int b)
{
	f[fr(a)]=fr(b);
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1;i<=n+k;i++)
		f[i]=i;
	for (int i=1,u,v,w;i<=m;i++)
	{
		scanf("%d%d%d",&u,&v,&w);
		g[u].push_back(node{v,w});
		q.push(node2{u,v,w});
	}
	long long ans=0;
	for (int i=1;i<=k;i++)
	{
		cin>>c[i];
		ans+=c[i];
		for (int j=1;j<=n;j++)
		{
			cin>>a[i][j];
			q.push(node2{j,n+i,a[i][j]});
		}
	}
	while (!q.empty())
	{
		int u,v,w;
		u=q.top().u;
		v=q.top().v;
		w=q.top().l;
		q.pop();
		if (fr(u)==fr(v))
			continue;
		add(u,v);
		ans+=w;
//		if (v>n)
//			use[v-n][u]=1;
	}
	/*
	for (int i=1;i<=k;i++)
	{
		memset(vis,0,sizeof(vis));
		for (int j=1;j<=n;j++)
			vis[j]=use[i][j];
		long long las=c[i];
		for (int j=1;j<=n;j++)
		{
			if (!vis[j])
				continue;
			f[j]=j;
			las+=a[i][j];
			for (node k:g[j])
				if (vis[k.v])
					q.push(node2{j,k.v,k.l});
		}
		long long as=0;
		while (!q.empty())
		{
			int u,v,w;
			u=q.top().u;
			v=q.top().v;
			w=q.top().l;
			q.pop();
			if (fr(u)==fr(v))
				continue;
			add(u,v);
			as+=w;
		}
		bool flag=
		for (
		if (las>as)
			ans=ans-las+as;
	}
	*/
	printf("%lld\n",ans);
	return 0;
}
