#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct node{
	int v,w;
};
vector<node> mp[10010];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		iny u,v,w; cin>>u>>v>>w;
		mp[u].push_back({v,w});
		mp[v].push_back({u,w});
	}
	for(int j=1;j<=k;j++){
		for(int i=0;i<=n;i++){
			int w; cin>>w;
		}
	}
	cout<<"I cannot solve this problem. What a pitty!";	
	return 0;
}
