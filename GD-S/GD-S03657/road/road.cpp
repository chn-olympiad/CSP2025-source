#include<bits/stdc++.h>
using namespace std;
const int MAXN=100005;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	int u,v,w,i;
	vector<pair<int,int>> graph(n);
	for(i=0;i<k;i++){
		cin>>u>>v>>w;
		graph(u).push_back({v,w});
		graph(u).push_back({u,w});
	}
	return 0;
}
	
