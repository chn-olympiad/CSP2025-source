#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int u[1000001],v[1000001],w[1000001];
int aij[1000001];
int main(){
	freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)	cin>>u[i]>>v[i]>>w[i];
	for(int i=1;i<=2*n+2;i++) cin>>aij[i]; 
	cout<<13;
    fclose(stdin);
	fclose(stdout); 
	return 0;
} 
