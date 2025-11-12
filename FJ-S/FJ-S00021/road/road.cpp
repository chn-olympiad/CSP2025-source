#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
typedef pair <int,int> PII;
int n,m,k;
vector <PII> road[10005];
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen ("road.in","r",stdin);
	freopen ("road.out","w",stdout);
	cin >> n >> m >> k;
	for (int i=1;i<=m;i++)
	{
		int u,v,w;
		cin >> u >> v >> w;
		road[u].push_back({v,w});
		road[v].push_back({u,w});
	}
	if (k==0)
	{
		
	}
	return 0;
}

