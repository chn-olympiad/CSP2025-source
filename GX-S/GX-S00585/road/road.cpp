#include<iostream>
#include<cstdio>
#include<queue>
#define ll long long
using namespace std;

ll n,m,k;
ll opv[10+10],done=0;
ll vis[10000+10],ans=0;
struct edge
{
	ll s,t,v,c;
	edge(){};
	edge(ll si,ll ti,ll vi,ll ci):s(si),t(ti),v(vi),c(ci){};
	bool operator<(edge that)const
	{
		return c+opv[v]>that.c+opv[that.v];
	}
};
priority_queue<edge>edgs;

void ku()
{
	edge t;
	while(!edgs.empty()&&done!=n)
	{
		t=edgs.top();
		edgs.pop();
		if(vis[t.s]&&vis[t.t])
			continue;
		if(opv[t.v])
		{
			ans+=opv[t.v];
			opv[t.v]=0;
		}
		ans+=t.c;
		if(t.s<=n&&!vis[t.s])
			done++;
		if(t.t<=n&&!vis[t.t])
			done++;
		vis[t.s]=vis[t.t]=true;
	}
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(ll i=1,s,t,c;i<=m;i++)
	{
		scanf("%lld%lld%lld",&s,&t,&c);
		edgs.push(edge(s,t,0,c));
	}
	for(ll i=1;i<=k;i++)
	{
		scanf("%lld",&opv[i]);
		for(ll j=1,c;j<=n;j++)
		{
			scanf("%lld",&c);
			edgs.push(edge(i+n,j,i,c));
		}
	}
	opv[0]=0;
	ku();
	cout<<ans;
	return 0;
}
