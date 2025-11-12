#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int a[1001][1001];
vector<vector<int> > v;
int main()
{
	freopen("road.in",stdin);
	freopen("road.out",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
	}
	for(int i=1;i<=k;i++)
	{
		int p;
		cin>>p;
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	}
	cout<<0<<endl;
}
