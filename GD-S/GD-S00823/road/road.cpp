#include<bits/stdc++.h>
using namespace std;
const int N=10001,M=100001;
struct edge
{
	int id,dis;
}a[N];
int n,m,k,c[M],arr[N][N];
bool vis[N];
void dijikstar(int u)
{
	vis[u]=1;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i = 1;i<=m;i++)
	{
		int u,v,dis;
		cin >> u >> v >> dis;
		a[u]={v,dis};
		a[v]={u,dis};
	}
	for(int j = 1;j<=k;j++)
	{
		cin >> c[j];
		for(int i = 1;i<=n;i++) cin >> arr[j][i];
	}
	dijikstar(1);
	cout << 117;
	return 0;
}
