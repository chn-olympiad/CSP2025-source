#include<bits/stdc++.h>
using namespace std;
long long n,m,k;
long long g[20005][11];
long long f[5005][5005];
void floyd(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(f[i][j]==0)
				f[i][j]=INT_MAX;
		}
		f[i][i]=0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		f[x][y]=z;
		f[y][x]=z;
	}
	int ans=INT_MAX;
	for(int i=1;i<=k;i++){
		int c;
		cin>>c;
		for(int j=1;j<=n;j++)
			cin>>g[j][i];
		for(int j1=1;j1<=n;j1++){
			for(int j2=1;j2<=n;j2++){
				if(j1==j2) continue;
				f[j1][j2]=g[j1][i]+g[j2][i];
			}
		}
	}
	floyd();
	for(int i=1;i<=n;i++){
		int sum=0;
		for(int j=1;j<=n;j++)
			sum+=f[i][j];
		ans=min(ans,sum);
	}
	cout<<ans;
	return 0;
}
