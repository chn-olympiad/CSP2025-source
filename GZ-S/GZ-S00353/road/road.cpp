//GZ-S00353 贵阳市第一中学 程思淇 
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout)
	int m=0,n=0,c=0,ans=0;
	int a[100001][100001]={};
	cin>>n>>m>>c;
	for(int i=1;i<=n;i++){
		int x=0,y=0;
		cin>>x>>y;
		cin>>a[x][y];
		a[y][x] = a[x][y];
	}
	for(int i=n+1;i<=c+n;i++){
		cin>>a[i][i];
		for(int j=1;j<=n;j++){
			cin>>a[j][i];
			a[i][j] = a[j][i];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			ans+=a[i][j];
		}
	}
	cout<<ans/2;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
