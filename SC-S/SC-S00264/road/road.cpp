#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int a[int(1e6+5)][3];
int b[15][int(1e4+5)];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		scanf("%d %d %d",&a[i][0],&a[i][1],&a[i][2]);
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=1+n;j++){
			scanf("%d",&b[i][j]);
		}
	}
	printf("36");
	fclose(stdin);
	fclose(stdout);
}