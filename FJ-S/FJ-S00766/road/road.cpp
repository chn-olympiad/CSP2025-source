#include<iostream>
using namespace std;
int u[1000005], v[1000005], w[1000005], a[15][10005], c[15];
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	int n, m, k;
	cin >> n >> m >> k;
	for(int i=1;i<=m;i++)
		cin >> u[i] >> v[i] >> w[i];
	for(int i=1;i<=k;i++){
		cin >> c[i];
		for(int j=1;j<=n;j++)
			cin >> a[i][j];
	}
	
	long long tot = 0;
	for(int i=1;i<=m;i++)
		tot += w[i];
	for(int i=1;i<=k;i++)
		tot -= c[i]; 
	cout << tot%10000000000;
	
	return 0;
}
