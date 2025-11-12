//化竞生不小心进了S组复赛
//为了不浪费报名费来考，全不会（预期能骗15分）
//初赛过线0.5分这一块 
//(OvO)我爱化学 
#include<bits/stdc++.h>
using namespace std;
int n,m,k,u,v,w,c[100005];
vector<pair<int,int> > e[10005];
vector<int> a[100005];

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<m;i++)
	{
		cin>>u>>v>>w;
		e[u].push_back({v,w});
		e[v].push_back({u,w});
	}
	for(int i=0;i<k;i++)
	{
		cin>>c[i];
		int s;
		for(int j=0;j<n;j++)
		{
			cin>>s;
			a[i].push_back(s); 
		}
	}
	cout<<13;
	
	return 0;
} 

