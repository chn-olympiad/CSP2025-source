#include<bits/stdc++.h>

using namespace std;
int n,m,k,u,v,w;
const int N = 1e6+5;
int c[15];
struct Node
{
	int u,v,w;
};
vector<Node> g[N];
int ans[N];
int cc;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i = 1;i <= m;i++)
	{
		cin >> u >> v >> w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
		ans[++cc] = w;
	}
	for(int i = 1;i <= k;i++)
	{
		cin >> c[i];
	}
	sort(ans+1,ans+1+cc);
	int cnt = 0;
	for(int i = 1;i <= n - 1;i++)
	{
		cnt += ans[i];
	}
	cout << cnt;
	return 0;
}
