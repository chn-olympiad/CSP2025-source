#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 6;
const int maxm = 1e6 + 8;
#define ll long long
struct edge{
	int u,v;
	ll w;
	bool operator <(const edge& x) const 
	{
		return w > x.w;
	}
};
int fa[maxn];
int get(int x)
{
	return fa[x] == x ? x : fa[x] = get(fa[x]);
}
int n,m,k;
ll ans;
int cnt;
edge ls;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	priority_queue<edge> q;
	for(int i=1;i<=n;i++)
	{
		fa[i] = i;
	}
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin >> u >> v >> w;
		q.push((edge){u,v,w}); 
	}
	for(int i=1;i<=k;i++)
	{
		int kl;
		cin >> kl;
		for(int j=1;j<=n;j++)
		{
			cin >> kl;
		}
	}
	while(cnt < n - 1)
	{
		ls = q.top();
		q.pop();
		if(get(ls.u) == get(ls.v))
		{
			continue;
		}
		fa[ls.u] = ls.v;
		ans += ls.w;
		cnt++;
	}
	cout << ans << '\n';
	return 0;
}
