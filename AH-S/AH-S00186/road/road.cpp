#include<bits/stdc++.h>
using namespace std;
long long g[int(1e3)+10][int(1e3)+10];
long long n,m,k,a[int(1e3)+10][int(1e3)+10],c[100];
bool cmp(const long long &x,const long long &y){
	return x > y;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		long long u,v,w;
		cin>>u>>v>>w;
		g[u][v]=w;
		g[v][u]=w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	if(m>=n-1){
		long long sum=0;
		for(int i=1;i<=n-1;i++){
			for(int j=1;j<=n-1;j++){
				sum+=g[i][j];
			}
		}
		cout<<sum;
	}
	return 0;
}
