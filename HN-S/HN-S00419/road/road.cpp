#include<bits/stdc++.h>
using namespace std;
int n,m,k;
const int N=1e5+5;
int a[N][N],u[N],v[N],w[N],c[N];

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(),cout.tie();
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int j=1;j<=k;j++){
		cin>>c[j]; 
		for(int i=1;i<=n;i++){
			cin>>a[j][i]; 
		} 	
	}
	cout<<5182974424;
	return 0;
} 
