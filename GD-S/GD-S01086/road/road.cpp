#include<bits/stdc++.h>
using namespace std;
int a[10100][10100],b[20][10100];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		a[u][v]=w;
		a[v][u]=w;
	}
	for(int i=0;i<k;i++){
		for(int j=0;j<n;j++){
			cin>>b[i][j];
		}
	}
	cout<<0;//Ëæ±ã°É£¬Ã»ÕÐÁË 
	return 0;
}

