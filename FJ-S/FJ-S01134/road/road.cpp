#include <bits/stdc++.h>
using namespace std;
int n,m,k;
struct node{
	int x;
	int y;
	int z;
}a[1000005]; 
int nu[10005];
int main(){
//	freopen("road.in","r",stdin);
//	freopen("road.out  ","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		a[i].y=INT_MAX;
	}
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		a[i].x=u;
		a[i].y=v;
		a[i].z=w;
		nu[u]++;
		nu[v]++;
	}
	
	
	
	int ans=0;
	if(k==0){
		queue <int> q;
	
		
		
	}

	
	return 0;
}
