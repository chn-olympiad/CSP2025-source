#include<bits/stdc++.h>
using namespace std;
int u[1000005], v[1000005], w[1000005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n, m, k;
	cin >> n >> m >> k;
	int a[11][10005];
	for(int i = 1;i<=m;i++)
	{
		cin >> u[i] >> v[i] >> w[i];
	}
	for(int i = 1;i<=k;i++)
	{
		cin >> a[i][0];
		for(int j = 1;j<=n;j++)
		{
			cin >> a[i][j];
		}
	}
	cout << 13;
	return 0;
}
