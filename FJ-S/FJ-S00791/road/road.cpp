#include <bits/stdc++.h>
#define P pair<int,int>
using namespace std;
const int N=1e5+10;
int a[N],head[N],cnt,d[N];
struct node
{
	int ne,to,w;
}e[N];
void add(int u,int v,int k)
{
	e[cnt].ne=head[u];e[cnt].to=v;e[cnt].w=k;
	head[u]=++cnt;
}
void dis()
{
	memset(d,0x3f,sizeof(d));
	d[1]=0;
	priority_queue<P,vector<P>,greater<P> >q;
	q.push({0,1});
	while(!q.empty())
	{
		auto t=q.top();
		int v=t.first;
		int h=t.second;
		q.pop();
		if(h<d[v])continue;
		for(int i=head[v];~i;i=e[i].ne)
		{
			int y=e[i].to;
			if(d[v]>d[y]+e[i].w)
			{
				d[v]=d[y]+e[i].w;
			//	q.push({y,d[h]});
			}
		}
	}
}
int main()
{
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		add(u,v,w);
	}
	dis();
	cout<<d[n];
	return 0;
}
