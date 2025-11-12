#include <bits/stdc++.h>
using namespace std;
int n,m,k;
vector<pair<int,long long> > e[1000006];
int a[10005];
long long d[10005];
void di(int x)
{
	memset(d,0x3f,sizeof(d));
	priority_queue<pair<long long,int>,vector<pair<long long,int> >,greater<pair<long long,int> > > q;
	q.push({0,x});
	d[x] = 0;
	while (!q.empty())
	{
		auto o = q.top();
		auto u = o.first;
		auto v = o.second;
		q.pop();
		for (auto i : e[v])
		{
			auto g = i.first;
			auto h = i.second;
			if (d[g] + h > u)
			{
				d[g] = d[g] + h;
				q.push({d[g],g});
			}
		}
	} 
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 1;i <= m;i++)
	{
		int u,v,w;
		cin >> u >> v >> w;
		e[u].push_back({v,w});
	}
	for (int i = 1;i <= k;i++)
	{
		int x;
		cin >> x;
		for (int i = 1;i <= n;i++)
		{
			cin >> a[i];
		}
	}
	di(1); 
	long long ans = 0;
	for (int i = 1;i <= n;i++)
	{
		cout << d[i] << " ";
	}
	cout << ans << "\n";
	return 0;
}
