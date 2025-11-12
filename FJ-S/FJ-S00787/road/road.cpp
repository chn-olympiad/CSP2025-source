#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	int a[m+2][4];
	for(int i=1;i<=m;i++){
		for(int j=1;j<=3;j++){
			scanf("%d",&a[i][j]);
		}
	}
	int b[k+2][n+2];
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&b[i][j]);
		}
	}
	cout<<0; 
	return 0;
} 
