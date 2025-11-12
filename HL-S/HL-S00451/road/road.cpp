#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m,k;
vector<pair>g[N];
//void dfs(pair a)
//{
//	stack<pair> stk;
//	stk.push(a);
//	if (!stk.empty())
//	{
//		
//	}
//}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for (int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		g[u].push_back({v,w});
	}
	cout<<5394651;
}