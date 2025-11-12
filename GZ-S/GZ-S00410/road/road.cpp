//GZ-S00410 清镇市博雅实验学校 许秉轩 
#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int a[100050][5],b[15][1050];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i][1]>>a[i][2]>>a[i][3];
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n+1;j++){
			cin>>a[i][j];
		}
	}
	
	return 0;
}
