#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>>a[1000011];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	int s=0;
	for(int i=1;i<=m;i++){
		int u,v,x;
		cin>>u>>x;
		a[u].push_back({v,x});
		a[v].push_back({u,x});
		s+=x;
	}
	for(int i=m+1;i<=m+1+k;i++){
		int c;
		cin>>c;
		for(int j=1;j<=n;i++){
			int x;
			cin>>x;
			a[j].push_back({i,x});
			a[i].push_back({j,x});
		}
	}
	cout<<s;
	return 0;
}
