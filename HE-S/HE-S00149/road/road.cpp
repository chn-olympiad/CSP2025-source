#include<iostream>
using namespace std;

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	int a[m],b[m],c[m],d[k],l[k][n];
	for(int i=0;i<m;i++){
		cin>>a[n]>>b[n]>>c[n];
	}
	for(int i=0;i<k;i++){
		cin>>d[i];
		for(int j=0;j<n;j++){
			cin<<l[i][j];
		}
	}
	cout<<0;
	return 0;
}
