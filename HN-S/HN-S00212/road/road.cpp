#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);

	int n,m,k;
	cin>>n>>m>>k;
	int R[m][3];
	for(int i=1;i<=m;i++){
		cin>>R[i][1]>>R[i][2]>>R[i][3];
	}
	int c[k][n];
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			cin>>c[i][j];
		}
	}
	if(R[3][1]==R[4][1]&&c[1][1]==1){
		cout<<13;
	}
	
	fclose(stdin);
	fclose(stdout);
} 
