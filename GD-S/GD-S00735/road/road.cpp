#include<bits/stdc++.h>
using namespace std;
int n,m,k,cnt,f[10005],ans,wi[10005];
priority_queue<pair<int,pair<int,int> >,vector<pair<int,pair<int,int> > >,greater<pair<int,pair<int,int> > > >q;
void into()
{
	for(int i=1;i<=n+k;i++)
	{
		f[i]=i;
	}
}
int findd(int x)
{
	if(f[x]==x) return x;
	else return f[x]=findd(f[x]);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	into();
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		q.push({w,{u,v}});
	}
	while(cnt!=n-1)
	{
		int x=findd(q.top().second.first),y=findd(q.top().second.second);
		if(x!=y)
		{
			f[x]=y;
			ans+=q.top().first;
			cnt++;
		}
		q.pop();
	}
	int t=ans;
	into();
	for(int i=1;i<=k;i++)
	{
		cin>>wi[i];
		for(int j=1;j<=n;j++)
		{
			int v,w;
			cin>>w;
			q.push({w,{m+i,j}});
		}
	}
	cnt=0;
	ans=0;
	while(cnt!=n-1)
	{
		int x=findd(q.top().second.first),y=findd(q.top().second.second);
		if(x!=y)
		{
			if(x>m)
			{
				ans+=wi[x-m];
			}
			else if(y>m)
			{
				ans+=wi[y-m];
			}
			f[x]=y;
			ans+=q.top().first;
			cnt++;
		}
		q.pop();
	}
	cout<<min(ans,t);
}
