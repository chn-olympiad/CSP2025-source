#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n,m,k;
vector<pair<int,int> > a[10086];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1,u,v,w;i<=m;i++)
	{
		cin>>u>>v>>w;
		a[u].push_back({v,w});
		a[v].push_back({u,w});
	}
	
	return 0;
} 

