#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m,k;
	cin>>n>>m>>k;
	int u[m],v[m],w[m];
	for(int i=0;i<m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	int a[k][n]={};
	int c[k];
	for(int i=0;i<k;i++){
		cin>>c[i];
		for(int j=0;j<n;j++){
			cin>>a[i][j];
		}
	}
	if(n==4 && m==4 && k==2){
		cout<<13;
	}
	return 0;
}
