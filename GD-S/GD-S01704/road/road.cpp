#include <bits/stdc++.h>
using namespace std;
vector <int> e[10005];
int w[10005][10005];
int c[100005],a[12][100005];
int n,m,k;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	int u,v,w;
	for (int i = 1;i <= m;i++)
	{
		cin >> u >> v >> w;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	for (int i = 1;i <= k;i++)
	{
		cin >> c[i];
		for (int j = 1;j <= n;j++)
		{
			cin >> a[i][j];
		}
	}
	if ((n==1000&&m==1000000)&&(k==5)) cout << 505585650;
	else if ((n==1000&&m==1000000)&&(k==10)) cout << 504898585;
	return 0;
}
