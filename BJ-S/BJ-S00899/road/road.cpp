#include<bits/stdc++.h>
using namespace std;
int n,m,k,s;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		s+=w;
	}
	for(int i=1;i<=k+1;i++){
		int tmp;
		cin>>tmp;
	}
	cout<<s;
	return 0;
}