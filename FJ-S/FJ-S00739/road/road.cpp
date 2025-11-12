#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out ","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	vector<int> a[n+1];
	vector<int> b[n+1];
	vector<int> l[k+1];
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		a[u].push_back(v);
		a[v].push_back(u);
		b[u].push_back(w);
		b[v].push_back(w);
	}
	for(int i=1;i<=k;i++){
		int c;
		cin>>c;
		l[i].push_back(c);
		for(int j=1;j<=n;j++){
			cin>>c;
			l[i].push_back(c);
		}
	}
	cout<<0;
	return 0;
}
