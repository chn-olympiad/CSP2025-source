#include <bits/stdc++.h>
using namespace std;

int n,m,k;
int u[100005],v[100005],w[100006];//对应m 
//   城市1       城市2    修路费用 
int c[15],a[1005];
//改造费  城乡修路费 
long long ans = 0;

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	//输入 
	cin >> n >> m >> k;
	for(int i = 1;i <= m;i++)
	{
		cin >> u[i] >> v[i] >> w[i];
	}
	for(int i = 1;i <= k;i++)
	{
		cin >> c[i];
		for(int j = 1;j <= n;j++)
		{
			cin >> a[j];
		}
	}
	for(int i = 1;i <= m;i++)
	{
		ans += w[i];
	}
	cout << ans;
	return 0;
 } 
