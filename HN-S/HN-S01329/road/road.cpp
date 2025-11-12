#include<bits/stdc++.h>
using namespace std;

int m[5000][5000];
int a[100][50000];
int c[1000000];
int r[50000][5000];

int main(){

	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	memset(m,0x3f3f3f,sizeof(m));
	int n,m1,k;
	cin>>n>>m1>>k;
	
	for(int i=0;i<m1;i++){
		int u,v,w;
		cin>>u>>v>>w;
		m[u][v]=w;
		m[v][u]=w;
	}
	for(int i=0;i<k;i++){
		cin>>c[n+i+1];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			m[n+i+1][j]=a[i][j];
			m[j][n+i+1]=a[i][j];
		}
	}
//	for(int aa=0;aa<n/2;aa++)
	for(int x=1;x<=n+k;x++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				m[i][j]=min(m[i][x]+m[x][j],m[i][j]);
				m[j][i]=m[i][j];
			}
		}
	}
	
//	int ans1=0,ans=900000000;
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			ans1+=m[i][j];
////			cout<<m[i][j]<<' ';
//		}
//		ans=min(ans,ans1);
//		ans1=0;
//	}
//	
//	for(int x=n+1;x<=n+k;x++){
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=n;j++){
//				m[i][j]=min(m[i][x]+m[x][j],m[i][j]);
//				m[j][i]=m[i][j];
//			}
//		}
//	}
	
	long long ans1=0,ans=900000000;
	for(int i=1;i<=n+k;i++){
		for(int j=1;j<=n;j++){
			ans1+=m[i][j];
			cout<<m[i][j]<<' ';
		}
		ans=min(ans,ans1+c[i]);
		ans1=0;
	}
	cout<<ans;
	return 0;

}

