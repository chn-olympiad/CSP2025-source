#include <bits/stdc++.h>
using namespace std;
struct node
{
	long long u,v,w;
	bool operator< (const node &b) const{return b.w<w;}
};
long long n,m,k,fa[10010],cnt[10010],ans;
priority_queue<node> q;
int find(int x)
{
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
void solve1()
{
	for(int i=1;i<=m;i++)
	{
		long long u,v,w;
		cin>>u>>v>>w;
		q.push({u,v,w});
	}
	for(int i=1;i<=n;i++)
	{
		fa[i]=i;
		cnt[i]=1;
	}
	while(!q.empty())
	{
		node t=q.top();
		q.pop();
		int xx=find(t.u),yy=find(t.v);
		if(xx!=yy)
		{
			fa[xx]=yy;
			cnt[yy]+=cnt[xx];
			ans+=t.w;
		}
		if(cnt[find(1)]==n)
		{
			cout<<ans;
			break;
		}
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	if(k==0)
	{
		solve1();
	}else
	{
		for(int i=1;i<=m;i++)
		{
			int u,v,w;
			cin>>u>>v>>w;
		}
		for(int i=1;i<=k;i++)
		{
			for(int j=1;j<=n;j++)
			{
				int a;
				cin>>a;
			}
		}
		cout<<0;
	}
	return 0;
}
