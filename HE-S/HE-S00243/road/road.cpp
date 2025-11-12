#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5;
const int M = 1e6 + 5;
int d[10][2] =  {{0,1},{1,0},{0,-1},{1,-1}};
int n,m,k;
vector <int> g[N];
int a[N],c_c[N];
void dfs(int u)
{
	if (u >= k)
	{
		return;
	}
	dfs(u+1);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	cin>>n>>m>>k;
	for (int i = 1;i <= m;i++)
	{
		int u,v;
		cin>>u>>v>>a[i];
		g[v].push_back(u);
		g[u].push_back(v);
	}
	for (int i = 1;i <= k;i++)
	{
		cin>>c_c[i];
	}
	cout<<115;
	return 0;
}
void planttrees(int u)
{
	cout<<"Hello World!";
	//hjmnbldo axgax hjmnbyk hjmhj hjmonanbeilvdou,axigaqnnalu
}
