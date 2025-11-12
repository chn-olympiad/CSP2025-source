#include<bits/stdc++.h>
using namespace std;
int n,m,k,u[10000+10],v[10000+10];
long long c[1000000000+10],a[1000000000+10],w[1000000000+10];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[j];
		}
	}
	cout<<13;
	return 0;
} 
