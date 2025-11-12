#include<bits/stdc++.h>
using namespace std;

const int N = 1e6+5;
int n,m,k;

struct nd{
	int v,w;
};
vector<nd> e[N];

struct edge{
	int u,v,w,dot=0;
	bool sp=0;
	bool operator<(edge y)	const
	{
		return w+dot < y.w+y.dot;
	}
};

priority_queue<edge> pq;

int c[11][10005];

int ans = 0;

void solve()
{
	return ;
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		e[u].push_back({v,w});
		e[v].push_back({u,w});
		ans += w;
	}
	for(int t=1;t<=k;t++)
	{
		for(int i=0;i<=n;i++)
		{
			cin>>c[t][i];
			ans += c[t][i];
		}
	}
	solve();
	return 0;
}
