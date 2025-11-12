#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> g[10005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	long long sum=0;
	for(int i=0;i<m;i++){
		int x,y,w;
		cin>>x>>y>>w;
		sum+=w;
		g[x].push_back({y,w});
		g[y].push_back({x,w});
	}
	cout<<w;
	return 0;
}
