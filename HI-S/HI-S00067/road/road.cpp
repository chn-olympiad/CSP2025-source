#include<bits/stdc++.h> 
using namespace std;
int f[10005];
int g[10005][10005];
int m,n,k,c[15],a[15][10005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			g[i][j]=1000000005;
		}
		f[i]=1000000005;
	}
	for(int i=0,ui,vi,wi;i<m;i++){
		cin>>ui>>vi>>wi;
		g[ui][vi]=wi;
	}
	for(int j=1;j<=k;j++){
		cin>>c[j];
		for(int i=1;i<=n;i++){
			cin>>a[j][i];
		}
	}
	f[1]=0;
	for(int k1=1;k1<=n;k1++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j)continue;
				g[i][j]=min(g[i][k1]+g[j][k1],g[i][j]);
			}
		}
	}
	for(int i=2;i<=n;i++){
		for(int k1=1;k1<k;k1++){
			for(int j=1;j<=n;j++){
				if(i==j)continue;
				f[i]=min(f[i],g[i][j]);
				f[i]=min(f[i],c[k1]+a[k1][i]+a[k1][j]);
			}
		}
	}
	cout<<f[n];
	return 0; 
} 
