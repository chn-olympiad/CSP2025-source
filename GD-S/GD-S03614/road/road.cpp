#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10;
int n,m,x,sum,vis[N],ans,d[100][100],c[100];
pair<int,int> minn[N];
vector<pair<int,int> > v[N];
priority_queue<pair<int,int> ,vector<pair<int, int> > ,greater<pair<int ,int> > > q;
void prim()
{
	vis[1]=true;
	for(auto i : v[1]) q.push({i.second,i.first});
	while(!q.empty())
	{
		pair<int,int> tmp=q.top();
		q.pop();
		vis[tmp.second]=true;
		int e=tmp.first;
		for(int i=1;i<=x;i++)
		{
			if(minn[i-1].first+d[i-1][minn[i-1].second-1]<e)
			{
				e=minn[i-1].first+d[i-1][minn[i-1].second-1];
			}
		}
		ans+=e;
		sum++;
		if(sum==n-1) break;
		for(int i=1;i<=x;i++)
			if(minn[i-1].first>d[i-1][tmp.second]) minn[i-1].first=d[i-1][tmp.second],minn[i-1].second=tmp.second;
		for(auto i : v[tmp.second])
			if(!vis[i.first]) q.push({i.second,i.first});
	}
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>x;
	for(int i=1;i<=m;i++)
	{
		int u,a,w;
		cin>>u>>a>>w;
		v[u].push_back({a,w});
		v[a].push_back({u,w});
	}
	bool flag=true;
	for(int i=1;i<=x;i++)
	{
		cin>>c[i-1];
		for(int t=1;t<=n;t++) cin>>d[i-1][t-1];
	}
	for(int i=1;i<=x;i++) minn[i-1].first=1e18;
	prim();
	cout<<ans<<endl;
	return 0;
}
