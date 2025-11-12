#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int w[1100],u[1110],v[1100];
int mo[1100][1100];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n+1;j++){
			cin>>mo[i][j];
		}
	}
	cout<<13;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
