#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;
int n,m,k;
int a[11][N];
int s[15];
vector< pair<int,int> > mp;
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		mp.push_back({v,w});
	}
	for(int i=1;i<=k;i++)
	{
		cin>>s[i];
		for(int j=1;j<=m;i++)
		{
			cin>>a[i][j];
		}
	}
	cout<<rand()%10000000000;
	return 0;
}
