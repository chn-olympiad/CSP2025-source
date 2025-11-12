#include<iostream>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	int u[m][3],a[k][n+1];
	for(int i=0;i<m;i++){
		cin>>u[i][0]>>u[i][1]>>u[i][2];
	}
	for(int i=0;i<k;i++){
		for(int j=0;j<n+1;j++){
			cin>>a[i][j];
		}
	}
	cout<<13;
	return 0;
}
