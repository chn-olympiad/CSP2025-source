#include<bits/stdc++.h>
using namespace std;
int n, m, k;
int e[1000005][3];
int a[15][10005];
long long ans = 0;

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++)
		cin >> e[i][0] >> e[i][1] >> e[i][2];
	for(int i = 1; i <= k; i++)
	{
		cin >> a[i][0];
		for(int j = 1; j <= n; j++)
			cin >> a[i][j];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
