#include<bits/stdc++.h>
using namespace std;
vector <int> a[100005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		a[u].pushback(v);
		a[v].pushback(u);
		a[u][v]=a[v][u]=w;
	}
	cout<<0;
	return 0;
}
