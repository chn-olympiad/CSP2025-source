#include<bits/stdc++.h>
using namespace std;
int ans = 0;
int u[100005],v[100005],w[100005];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin >> n >> m >> k;
	for(int i = 1;i<=m;i++)
	{
		cin >> u[i] >> v[i] >> w[i];
		ans += w[i];
	}
	cout << ans;
	return 0;
}
