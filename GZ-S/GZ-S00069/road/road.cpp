//GZ-S00069 毕节东辰实验学校 刘顶峰 
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
#define ll long long
struct node
{
	ll i=0,w=0;
	ll f=0;
};
struct cmp
{
	bool operator()(node a,node b)
	{
		return a.w>b.w;
	}
};
ll ans=0;
vector<node>tr[1008611];
ll w[1008611]={0};
ll vis[1008611]={0};
ll f[1008611]={0};
ll cun[20][10005]={{0}};
ll n=0,m=0,k=0;
ll dis[1008611]={0};
void dij()
{
	for(int j=1;j<=n;j++)
	{
		dis[j]=1008611111111;
	}
	priority_queue<node,vector<node>,cmp>q;
	dis[1]=0;
	ll u=1,L=1;
	node v;
	v.i=1,v.w=0;
	q.push(v);
	while(!q.empty())
	{
		ll u=q.top().i;
		ll sum=q.top().w;
		ll p=q.top().f;
		q.pop();
		if(vis[u])
			continue;
		vis[u]=1;
		ans+=sum;
		for(int j=0;j<tr[u].size();j++)
		{
			v.i=tr[u][j].i;
			v.w=tr[u][j].w;
				q.push(v);
		}
		for(int j=1;j<=k;j++)
		{
			for(int i=1;i<=n;i++)
			{
				if(i==u)
					continue;
				v.i=i,v.w=cun[j][u]+cun[j][i],v.f=j;
					q.push(v);
			}
		}
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(ll i=1;i<=m;i++)
	{
		ll a=0,b=0,w=0;
		cin>>a>>b>>w;
		node t;
		t.i=b,t.w=w;
		tr[a].push_back(t);
		t.i=a;
		tr[b].push_back(t);
	}
	for(ll j=1;j<=k;j++)
	{
		cin>>w[j];
		for(ll i=1;i<=n;i++)
		{
			cin>>cun[j][i]; 
		}
	}
	dij();
	printf("%lld",ans);
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
