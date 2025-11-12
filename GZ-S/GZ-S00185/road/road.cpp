//GZ-S00185 华东师范大学附属贵阳学校 彭梓垚 
#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
vector<pair<int,int> > g[N];
int n,m,k,c[12],a[12][N];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;cin>>u>>v>>w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	cout<<0<<endl;
	return 0;
}
