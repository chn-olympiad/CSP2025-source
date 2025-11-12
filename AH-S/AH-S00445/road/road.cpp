#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<pair<int,int> >v[10005];
int mn=1e9;
int d[10005];
int n,m,k;
void bfs(int i)
{
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q;
	q.push(make_pair(0,i));
	memset(d,127,sizeof(d));
	d[i]=0;
	while(!q.empty())
	{
		int kk=q.top().second;
		q.pop();
		for(int i=0;i<(int)(v[kk].size());i++)
		{
			int nx=v[kk][i].second;
			if (d[nx]>d[kk]+v[kk][i].first)
				q.push(make_pair(d[kk]+v[kk][i].first,nx)),
				d[nx]=d[kk]+v[kk][i].first;
		}
	}
	int mx=-1;
	for(int i=1;i<=n;i++)
		mx=max(mx,d[i]);
	mn=min(mn,mx);
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int mx=-1;
	for(int i=1;i<=m;i++)
	{
		int x,y,c;
		cin>>x>>y>>c;
		mx=max(mx,c);
		v[x].push_back(make_pair(c,y));
		v[y].push_back(make_pair(c,x));
	}
	if (mx==0) 
	{
		cout<<0;
		return 0;
	}
 	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=n+1;j++)
		{
		int x;cin>>x;
		}
	}
	for(int i=1;i<=n;i++) bfs(i);
	cout<<mn;
	return 0;
}
