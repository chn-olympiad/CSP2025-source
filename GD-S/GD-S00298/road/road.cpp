#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,k,x,y,z,c[15][10005],fa[10005],t;
pair<int,int>l[1500005];
ll sum;
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q;
int find(int x)
{
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
void join(int x,int y)
{
	int u=find(x),v=find(y);
	if(u!=v)fa[u]=v;
	return;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		t++;
		l[t].first=x,l[t].second=y;
		q.push(make_pair(z,t));
	}
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&c[i][0]);
		for(int j=1;j<=n;j++)scanf("%d",&c[i][j]);
	}
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int r=1;r<=n;r++)
			{
				t++;
				l[t].first=j,l[t].second=r;
				q.push(make_pair(c[i][j]+c[i][r]+c[i][0],t));
			}
		}
	}
	for(int i=1;i<=n;i++)fa[i]=i;
	while(!q.empty())
	{
		z=q.top().second;
		x=find(l[z].first),y=find(l[z].second);
		if(x!=y)
		{
			sum+=q.top().first;
			join(x,y);
		}
		q.pop();
	}
	printf("%lld",sum);
	return 0;
}
