#include<bits/stdc++.h>
using namespace std;
const long long MAXN=1e4+5;
long long n,m,k,minn=MAXN;
long long cost_city[MAXN];//城市化乡村
long long is_cross[MAXN];//通了么
long long empty[MAXN];//空的（没用）
long long cost[MAXN];
long long roadduty[MAXN][3];
struct through
{
	long long cost;
	long long line;
}city[MAXN][MAXN]; //乡村通往城市
//		当前正在修的道路		还有几个没有修	总花费			需要买的城市
void dfs(long long x,long long light,long long pay,long long pay_city[])
{
	if(x>m)
	{
		if(light==0) minn=min(minn,pay);
		return ;
	}
	dfs(x+1,light,pay,pay_city);
	long long minm=cost[x],minnm=0;
	for(long long i=1;i<=k;++i)
	{
		if(city[i][roadduty[x][1]].cost*(1-city[i][roadduty[x][1]].line)+city[i][roadduty[x][2]].cost*(1-city[i][roadduty[x][2]].line)<minm&&pay_city[i]==1)
		{
			minm=city[i][roadduty[x][1]].cost*(1-city[i][roadduty[x][1]].line)+city[i][roadduty[x][2]].cost*(1-city[i][roadduty[x][2]].line);
			minnm=i;
		}
	}
	light-=2-is_cross[roadduty[x][1]]+is_cross[roadduty[x][2]];
	is_cross[roadduty[x][1]]=is_cross[roadduty[x][2]]=1;
	if(minnm!=0)
	{
		city[minnm][roadduty[x][1]].line=1;
		city[minnm][roadduty[x][2]].line=1;
	}
	pay+=minm;
	dfs(x+1,light,pay,pay_city);
	return ;
}
void start(long long x,long long line[],long long ans)
{
	if(x>k) 
	{
		dfs(1,n,ans,line);
		memset(is_cross,0,sizeof(is_cross));
		return ;
	}
	start(x+1,line,ans);
	line[x]=1;
	ans+=cost_city[x];
	start(x+1,line,ans);
	return ;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(long long i=1;i<=m;++i)
	{
		long long x,y,z;
		scanf("%lld%lld%lld",&x,&y,&z);
		cost[i]=z;
		roadduty[i][1]=x;
		roadduty[i][2]=y;
	}
	for(long long i=1;i<=k;++i)
	{
		scanf("%lld",&cost_city[i]);
		for(long long j=1;j<=n;++j)
		{
			long long x;
			scanf("%lld",&x);
			city[i][j].cost=x;
		}
	}
	start(1,empty,0);
	printf("%lld",minn);
	return 0;
}
