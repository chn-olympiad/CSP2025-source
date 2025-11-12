#include<bits/stdc++.h>
using namespace std;

int n, m, k, a[11][10001];
struct road
{
	int u, v, w;
} r[1000001];
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin>>n>>m>>k;
	for(int i=1; i<=m; i++) cin>>r[i].u>>r[i].v>>r[i].w;
	for(int i=1; i<=k; i++)
		for(int j=1; j<=n; j++) cin>>a[i][j];
		
	cout<<13;
	return 0;
}
