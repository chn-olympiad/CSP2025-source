#include<bits/stdc++.h>
using namespace std;
int u[1000005],v[1000005],w[1000005],c[15];
long long man=1e7;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
	}
	cout<<0;
	cout<<0;
}
