#include<bits/stdc++.h>
using namespace std;
const long long maxn=1e4+15;
const long long maxm=1e6+5;
struct edge
{
	long long a,b,w,id;
}e[maxm<<1];
bool cmp(edge a,edge b)
{
	return a.w<b.w;
}
long long n,m,k;
long long c[15];
long long fa[maxn],b[15];
long long find(long long x)
{
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
bool join(long long x,long long y)
{
	long long xx=find(x),yy=find(y);
	if(xx==yy)
	{
		return false;
	}
	else
	{
		fa[xx]=yy;
		return true;
	}
} 
long long solve()
{
	long long ans=0;
	for(long long i=1;i<=n+k;i++)
	{
		fa[i]=i;
	}
	long long nn=0;
	for(long long i=1;i<=k;i++)
	{
		if(b[i]==1)
		{
			nn++;
			ans+=c[i];
		}
	}
	long long cnt=0;
	for(long long i=1;i<=m;i++)
	{
		if(b[e[i].id]==0)
		{
			continue;
		}
		bool t=join(e[i].a,e[i].b);
		if(t==1)
		{
			cnt++;
			ans+=e[i].w;
		}
		if(cnt==n+nn-1)
		{
			break;
		}
	}
	return ans;
}
long long ans=LONG_LONG_MAX;
void dfs(long long now)
{
	if(now>k)
	{
		ans=min(ans,solve());
//		cout<<solve()<<'\n';
		return ;
	}
	b[now]=1;
	dfs(now+1);
	b[now]=0;
	dfs(now+1);
	return ;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	cin>>n>>m>>k;
	b[0]=1;
	for(long long i=1;i<=m;i++)
	{
		cin>>e[i].a>>e[i].b>>e[i].w;
		e[i].id=0;
	}
	for(long long i=1;i<=k;i++)
	{
		cin>>c[i];
		for(long long j=1,w;j<=n;j++)
		{
			cin>>w;
			e[++m].a=n+i;e[m].b=j;e[m].w=w;e[m].id=i;
		}
	}
	sort(e+1,e+m+1,cmp);
	dfs(1);
	cout<<ans<<'\n'; 
}
