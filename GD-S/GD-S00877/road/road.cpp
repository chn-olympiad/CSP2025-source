#include <bits/stdc++.h>
using namespace std;
int n,m,k,x,y,z,a[10010][10010],f[10010][10010];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n+k;i++){
		for(int j=1;j<=n+k;j++){
			a[i][j]=999999;
			a[j][i]=999999;
		}
	}
	for(int i=1;i<=m;i++){
		cin>>x>>y>>z;
		a[x][y]=z;
		a[y][x]=z;
	}
	for(int i=1;i<=k;i++){
		cin>>x>>y>>z;
		a[x][y]=z;
		a[y][x]=z;
	}
	for(int i=1;i<=n+k;i++){
		for(int j=1;j<=n+k;j++){
			for(int l=1;l<=n+k;l++){
				if(i==j || i==l || l==j) continue;
				if(f[i][j]>f[i][k]+f[j][k]) f[i][j]=f[i][k]+f[j][k]; 
			}
		}
	}
	int sum;
	for(int i=1;i<=n+k;i++){
		for(int j=1;j<=n+k;j++){
			sum+=f[i][j];
		}
	}
	cout<<sum/2;
	return 0;
}
