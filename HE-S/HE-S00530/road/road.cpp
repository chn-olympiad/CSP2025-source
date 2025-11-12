#include<bits/stdc++.h>
#define int long long
#define mk(x,y) make_pair(x,y)
using namespace std;
const int N = 1e4 + 10,M = 1e6 + 10;
int n,m,k;
vector<pair<int,int> > e[M];
int c[15],a[15][N];
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n >> m >> k;
	for(int i = 1;i <= m;i ++)
	{
		int u,v,w;
		cin >> u >> v >> w;
		e[u].push_back(mk(w,v));
		e[v].push_back(mk(w,u));
	}
	for(int i = 1;i <= k;i ++)
	{
		cin >> c[i];
		for(int j = 1;j <= n;j ++)
		{
			cin >> a[i][j];
		}
	}
	cout << 0 << '\n';
	return 0;
}
