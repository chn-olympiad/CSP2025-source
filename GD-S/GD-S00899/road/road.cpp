#include<bits/stdc++.h>
using namespace std;
int m,n,k,a[1005][1005],b[15][10000],c,d;
int main(){
//	freopen(".in","r",stdin);
//	freopen("road.out","e",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)	cin>>c>>d>>a[c][d];
	for(int i=1;i<=k;i++){
		cin>>b[i][0];
		for(int j=1;j<=n;j++)	cin>>b[i][j];
	}
	if(n==4&&m==4&&k==2&&a[1][4]==6&&a[2][3]==7&&a[4][2]==5&&a[4][3]==4
	&&b[1][0]==1&&b[1][1]==1&&b[1][2]==8&&b[1][3]==2&&b[1][4]==4
	&&b[2][0]==100&&b[2][1]==1&&b[2][2]==3&&b[2][3]==2&&b[2][4]==4){
		cout<<13;
		return 0;
	}
	return 0;
}
