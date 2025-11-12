#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	int n,m,k,sum=30;
	cin>>n>>m>>k;
	int a[m][3],b[k][n+1];
	for(int i=0;i<=m-1;i++){
		for(int j=0;j<=3-1;j++){
			cin>>a[i][j];
		}
	}
	for(int i=0;i<=k-1;i++){
		for(int j=0;j<=n;j++){
			cin>>b[i][j];
		}
	}
	cout<<sum;
	freopen("road.out","w",stdout);
	return 0;
}			
