#include<bits/stdc++.h>
using namespace std;
vector<int>a[10010],w[10010];
int b1[10010];
vector<int>b2[10010];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,ww;
		cin>>u>>v>>ww;
		a[u].push_back(v);a[v].push_back(u);
		w[u].push_back(ww);w[v].push_back(ww);
	}
	for(int i=1;i<=k;i++){
		cin>>b1[i];
		for(int j=0;j<a[i].size();j++){
			int b22;
			cin>>b22;
			b2[i].push_back(b22);
		}
	}
	
	return 0;
}
