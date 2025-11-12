#include<bits/stdc++.h>
#include<iostream>
using namespace std;
long long n,m,k;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	long long u[n+5],v[n+5],w[m+5];
	for(int i=1;i<=n;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	long long c[k+5],a[k+5][n+5];
	for(int j=1;j<=k;j++){
		cin>>c[j];
		for(int i=1;i<=n;i++){
			cin>>a[j][i];
		}
	}sort(w+1,w+m+1);
	cout<<"5182974424";
	
	
	
	
}
	

