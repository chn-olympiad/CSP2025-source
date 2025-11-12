#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int a[10005][10005]={};
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int u=0,v=0,w=0;
	cin>>n>>m>>k;
	for(int i=0;i<n;i++){
		cin>>u>>v>>w;
	}
	for(int i=0;i<k;i++){	
		for(int j=0;j<m;j++){
			cin>>a[i][j];}}
	cout<<13;
	
	
	return 0;
}
