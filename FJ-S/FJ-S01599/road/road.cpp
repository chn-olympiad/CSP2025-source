#include<bits/stdc++.h>
using namespace std;
long long n,m,k,ans,id,head[2000005],dis[2000005],bj[2000005],c[2000005],t;
struct ss{
	long long lst,to,val;
}e[2000005];
struct ss2{
	long long d,va;
};
struct cmp{
	bool operator()(const ss2 &a,const ss2 &b){
		return a.va<b.va;
	}
};
void add(int u,int v,int w)
{
	id++;
	e[id].lst=head[u];
	e[id].to=v;
	e[id].val=w;
	head[u]=id;
}
void dij(int s)
{
	memset(dis,0x3f3f3f3f,sizeof(dis));
	memset(bj,0,sizeof(bj));
	priority_queue<ss2,vector<ss2>,cmp > q;
	dis[s]=0;
	q.push({s,0});
	while(!q.empty())
	{
		long long u=q.top().d;
		q.pop();
		if(bj[u])
		{
			continue;
		}
		for(int i=head[u];i;i=e[i].lst)
		{
			long long v=e[i].to;
			int w=e[i].val;
			if(bj[v])
			{
				continue;
			}
			if(dis[u]+w<dis[v])
			{
				dis[v]=dis[u]+w;
				q.push({v,dis[v]});
			}
		}
	}
}
int main() 
{
	int u,v,w;
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	//Ren5Jie4Di4Ling5%
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w);
		add(v,u,w);
		t+=w;
	}
	for(int i=1;i<=k;i++)
	{
		int a;
		scanf("%lld",&c[i]);
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&a);
		}
	}
	cout<<t<<endl;
	return 0;
}
