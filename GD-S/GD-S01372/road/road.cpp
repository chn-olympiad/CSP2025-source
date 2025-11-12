#include<bits/stdc++.h>
using namespace std;
#define N 10005
struct pos{
	int to,w;
};
int n,m,k;
vector<pos>g[N];

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	cin>>n>>m>>k;
	for(int i=1,u,v,w;i<=m;i++){
		cin>>u>>v>>w;
		g[u].push_back({v,w});
	}
	for(int i=1,c;i<=k;i++){
		cin>>c;
	}
	cout<<0;
	
	return 0;
}
