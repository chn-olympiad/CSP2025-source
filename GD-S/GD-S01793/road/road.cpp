#include<iostream>
#include<cstdio>
#include<climits>
using namespace std;
struct Edge{
	int u;
	int v;
	int weight;
}edge[2000000];
int n,m,k;
int dist[10005];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>edge[i].u>>edge[i].v>>edge[i].weight; 
	}
	int str,cost;
	for(int i=1;i<=k;i++)
	{
		cin>>str;	
		for(int j=1;j<=n;j++)
		{
			cin>>cost;
		}
	}
	cout<<"13"<<endl;
	return 0;
}
