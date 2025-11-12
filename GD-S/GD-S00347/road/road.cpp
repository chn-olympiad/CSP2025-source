#include<bits/stdc++.h>
using namespace std;
int n,m,k,ans;
struct EDGE
{
	int u,v,w;
	bool operator >(const EDGE &other) const
	{
		return w>other.w;
	}
};
priority_queue<EDGE,vector<EDGE>,greater<EDGE> > q;
int fa[20010];
int find(int x)
{
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void solve()
{
	for(int i=1;i<=n;i++) fa[i]=i;
	while(!q.empty())
	{
		EDGE t;t=q.top();q.pop();
		int u=t.u,v=t.v,w=t.w;
		int xx=find(u),yy=find(v);
		if(xx!=yy)
		{
			fa[xx]=yy;
			ans+=w;
		}
		set<int> st;
		bool ok=true;
		for(int i=1;i<=n;i++)
		{
			int t=find(i);
			if(st.find(t)==st.end())
			{
				st.insert(t);
			}
			if(st.size()>1)
			{
				ok=false;
				break;
			}
		}
		if(ok==true) break;
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int x,y,z;
		cin>>x>>y>>z;
		q.push({x,y,z});
	}
	for(int i=1;i<=k;i++)
	{
		int x;
		cin>>x;
		for(int j=1;j<=n;j++)
		{
			int y;
			cin>>y;
			q.push({i,j,x+y});
		}
	}
	solve();
	cout<<ans;
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
0 0 0 0 0
0 0 0 0 0
*/
