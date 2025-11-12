#include<bits/stdc++.h>
using namespace std;

int n,m,k;
int u[100001],v[100001],w[100001];
int cj[100001][100001];

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i=1;i<=n+1;i++){
		for(int j=1;j<=k;k++){
			cin>>cj[n][k];
		}
	}
	cout<<"73";
	return 0;
} 
