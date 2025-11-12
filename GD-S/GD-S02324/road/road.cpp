#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,h=0;
	cin>>n>>m>>k;
	int u[n],v[n],w[n];
	for(int i=0;i<n;i++){
		cin>>u[i]>>v[i]>>w[i];
		h+=w[i];
	}
	cout<<h;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
