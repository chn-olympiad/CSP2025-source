#include<bits/stdc++.h>
using namespace std;
struct edge
{
	long long h;
	long long t;
	long long v;
}bef[1000010];
long long n,m,k,lowans=LONG_LONG_MAX,parent[10020],change[15][1010];
priority_queue<edge> pq;
char ch;
long long read()
{
	long long res=0;
	while((ch=getchar())!=' '&&ch!='\n')
	{
		res*=10;
		res+=ch-'0';
	}
	return res;
}
bool operator<(const edge &l,const edge &r)
{
	return l.v>r.v;
}
long long find(long long node)
{
	if(parent[parent[node]]==parent[node])return parent[node];
	parent[node]=parent[parent[node]];
	return find(node);
}
void solve(long long choose)
{
	long long lef,rig,ans=0,add=0;
	for(long long i=1;i<=m;i++)
	{
		pq.push(bef[i]);
	}
	for(long long i=0;i<k;i++)
	{
		if((choose>>i)&1)
		{
			add++;
			ans+=change[i+1][0];
			for(long long j=1;j<=n;j++)
			{
				pq.push({n+add,j,change[i+1][j]});
			}
		}
	}
	for(long long i=1;i<=n+add;i++)
	{
		parent[i]=i;
	}
	for(long long i=0;i<n+add-1;i++)
	{
		if(ans>=lowans)return;
		lef=pq.top().h;rig=pq.top().t;
		while(find(lef)==find(rig))
		{
			pq.pop();
			lef=pq.top().h;rig=pq.top().t;
		}
		ans+=pq.top().v;
		parent[find(lef)]=parent[find(rig)];
		pq.pop();
	}
	lowans=min(lowans,ans);
	while(!pq.empty())pq.pop();
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();
	m=read();
	k=read();
	for(long long i=1;i<=m;i++)
	{
		bef[i].h=read();
		bef[i].t=read();
		bef[i].v=read();
	}
	for(long long i=1;i<=k;i++)
	{
		for(long long j=0;j<=n;j++)
		{
			change[i][j]=read();
		}
	}
	for(long long i=0;i<(1<<k);i++)
	{
		solve(i);
		if(lowans==0)
		{
			cout<<0<<endl;
			return 0;
		}
	}
	cout<<lowans<<endl;
	return 0;
}
