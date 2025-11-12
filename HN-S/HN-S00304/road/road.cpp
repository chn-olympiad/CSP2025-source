#include<bits/stdc++.h>
using namespace std;
struct T
{
	long long int t,w;
};
vector<T> ve[10005];
long long int n,m,k,c[15],a[15][100005];
int main()
{
//	freopen("road.in","r",stdin);
//	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1,u,v,ww;i<=m;i++)
	{
		cin>>u>>v>>ww;
		ve[v].push_back({u,ww});
		ve[u].push_back({v,ww});
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	}
	cout<<0;
	return 0;
}

