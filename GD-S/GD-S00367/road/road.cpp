#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct node
{
	int id,dis;	
};
vector<int> G[10005];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	cout<<n+m+k;
	return 0;
}
