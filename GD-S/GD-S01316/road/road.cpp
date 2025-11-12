#include<bits/stdc++.h>
using namespace std;
int n,m,k,a[10100][10100],u,v,w;
int main(){
	cin>>n>>m>>k;
	while(m--){
		cin>>u>>v>>w;
		if(a[u][v]==0||a[u][v]>w){
			a[u][v]=w;
		}
		
	}
	return 0;
}
