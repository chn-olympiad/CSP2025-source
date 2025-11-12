#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("road.in","r",stdin);
	//freopen("road.out","w",stdout);
	int n,m,k,x,y,z,ans=0;
	cin>>n>>m>>k;
	int a[n+2][n+2]={INT_MAX},b[n+2]={INT_MAX};
	for(int i=1;i<=m;i++){
		cin>>x>>y>>z;
		a[x][y]=a[y][x]=min(a[x][y],z);
	}
	for(int i=1;i<=k;i++){
		cin>>x;
		for(int j=1;j<=n;j++){
			cin>>y;
			b[j]=min(y,b[j]);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			a[i][j]=a[j][i]=min(a[i][j],b[i]+b[j]);
		}
	}
	x=INT_MAX;
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<i;j++){
				if(x>a[i][j]){
					x=a[i][j];
					y=i,z=j;
				}
			}
		}
		ans+=x;
		a[y][z]=INT_MAX;
	}
	cout<<ans<<endl;
	return 0;
}
