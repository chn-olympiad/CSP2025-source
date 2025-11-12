#include<bits/stdc++.h>
using namespace std;
struct node
{
	int x,y,z;
	bool operator < (const node &b) const
	{
		if(z==b.z)
		{
			if(x==b.x) return y<b.y;
			return x<b.x;
		}
		return z>b.z;
	}
};
vector<pair<int,int> >to[10100];
int n,m,k,c[20],num,val[10100];
bool used[10100];
bool vis[10100];
long long ans;
priority_queue<node>q;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m>>k;
	int x,y,z;
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y>>z;
		to[x].push_back({z,y});
		to[y].push_back({z,x});
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			cin>>x;
			to[j].push_back({x+c[i],n+i});
			to[n+i].push_back({x,j});
		}
	}
	node nod;
	nod.x=0;nod.y=1;nod.z=0;
	q.push(nod);
	while(num<n)
	{
		x=q.top().y;
		if(vis[x])
		{
			q.pop();
			continue;
		}
		used[q.top().x]=1;
		val[x]=q.top().z;
//		cout<<x<<"\n";
		ans+=q.top().z;
		vis[x]=1;
		if(x<=n) num++;
		for(int i=to[x].size()-1;i>=0;i--)
		{
			z=to[x][i].second;
			if(vis[z]) continue;
			nod.x=x;nod.y=z;nod.z=to[x][i].first;
			q.push(nod);
		}
	}
	for(int i=1;i<=k;i++)
		if(!used[n+i]) ans-=val[n+i];
	cout<<ans<<"\n";
}