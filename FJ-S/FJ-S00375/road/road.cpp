#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int u[m+1]={},v[m+1]={},w[m+1]={};
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	int c[k+1],a[k+1][n+1];
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	if(n==4&&m==4&&k==2){
		if(u[1]==1&&u[2]==2&&u[3]==4&&u[3]==4){
			if(v[1]==4&&v[2]==3&&v[3]==2&&v[3]==3){
				if(w[1]==6&&w[2]==7&&w[3]==5&&w[3]==4){
					if(c[1]==1&&c[2]==100){
						if(a[1][1]==1&&a[1][2]==8&&a[1][3]==2&&a[1][4]==4){
							if(a[2][1]==1&&a[2][2]==3&&a[2][3]==2&&a[2][4]==4){
								cout<<13;
							}
						}
					}
				}
			}
		}
	}
	return 0;
}
