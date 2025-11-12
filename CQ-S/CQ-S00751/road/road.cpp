#include<bits/stdc++.h>
using namespace std;
long long n,m,k,ans=LONG_LONG_MAX,vis[1000010],c[1000010],u[1000010],v[1000010],w[1000010],fa[1000010],kw[15][1000010],exu[2000010],exv[2000010];
long long find(long long x)
{
	if(fa[x]==x) return fa[x];
	return fa[x]=find(fa[x]);
}
vector<pair<long long ,long long> >G[1000010];
priority_queue<pair<long long,long long> >q;
void solve()
{
	long long res=0,tot=m;
	for(int i=1;i<=m;i++)
	{
		q.push({-w[i],i});
	}
	for(int i=1;i<=k;i++)
	{
		if(vis[i])
		{
			res+=c[i];
			for(int j=1;j<=n;j++)
			{
				tot++;exu[tot]=i;exv[tot]=j;
				q.push({-kw[i][j],tot});
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		fa[i]=i;
	}
	while(!q.empty())
	{
		long long val=-q.top().first,id=q.top().second,x=0,y=0;q.pop();
		if(id>m)
		{
			x=exu[id];y=exv[id];
		}
		else
		{
			x=u[id];y=v[id];
		}
		if(x>y) swap(x,y);
		long long tp1=find(x),tp2=find(y);
		if(tp1!=tp2)
		{
			fa[tp1]=fa[tp2];
			res+=val;
		}
	}
	ans=min(ans,res);
}
void dfs(long long K)
{
	if(K==k+1)
	{
		solve(); 
		return ;
	}
	vis[K]=0;
	dfs(K+1);
	vis[K]=1;
	dfs(K+1);
	vis[K]=0;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			cin>>kw[i][j];
		}
	}
	dfs(1);
	cout<<ans;
	return 0;
}
/*
似乎是最小生成树
最朴素的想法：枚举每个乡镇是否城市化，将其边加入
跑一遍最小生成树
应该可以拿40pts 
*/
