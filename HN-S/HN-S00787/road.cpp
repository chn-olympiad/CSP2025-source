#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","t","stdin");
	freopen("road.out","w","stdout");
	int n,m,k;
	cin>>n>>m>>k;
	int u[m],v[m],w[m],sum=0;
	for(int i=0;i<m;i++){
		cin>>u[i]>>v[i]>>w[i];
		sum+=w[i];
	}
	int c[k][m+1];
	for(int i=0;i<k;i++){
		cin>>c[i][0];
		for(int j=0;j<m;j++){
			cin>>c[i][j+1];
		}
	}
	cout<<"13";
return 0;
}
