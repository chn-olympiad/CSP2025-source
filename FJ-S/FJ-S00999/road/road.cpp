#include<bits/stdc++.h>
using namespace std;
struct edge
{
	long long v,w,nxt;
} e[1000010];
long long head[10010],cnt;
long long a[15][10010],c[20];
long long vis[10010];
long long ans=0;
long long n,m,k;
priority_queue<pair<long long,long long> >q;
void jr(int x,int y,int z)
{
	cnt++;
	e[cnt].v=y;
	e[cnt].w=z;
	e[cnt].nxt=head[x];
	head[x]=cnt;
}
void pri()
{
	vis[1]=1;
	for(int i=head[1];i;i=e[i].nxt)
	{
		q.push(make_pair(-e[i].w,e[i].v));
	}
	while(q.size())
	{
		int now=q.top().second,wei=q.top().first;
		q.pop();
		if(vis[now]==1) continue;
		vis[now]=1;
		ans+=-wei;
		for(int i=head[now];i;i=e[i].nxt)
		{
			q.push(make_pair(-e[i].w,e[i].v));
		}
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int x,y,z;
		cin>>x>>y>>z;
		jr(x,y,z);
		jr(y,x,z);
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
		}
		for(int j=1;j<=n;j++)
		{
			for(int h=j+1;h<=n;h++)
			{
				jr(j,h,c[i]+a[i][j]+a[i][h]);
				jr(h,j,c[i]+a[i][j]+a[i][h]);
			}
		}
	}
	pri();
	cout<<ans;
	return 0;
}
