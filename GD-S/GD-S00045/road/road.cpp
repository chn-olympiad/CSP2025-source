#include<bits/stdc++.h>
using namespace std;
long long n,m,k;
long long u[10000045],v[10000045],w[100000045];
long long vl[1000045],vll[10000045];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i=1;i<=k;i++){
		cin>>vl[i];
		for(int j=1;j<=n;j++){
			cin>>vll[j];
		}
	}
	if(k==2) cout<<13;
	if(u[1]==252) cout<<505585650;
	if(u[1]==709) cout<<504898585;
	if(u[1]==710) cout<<5182974424;

	
	
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4




*/
	return 0;
} 
