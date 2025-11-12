#include<bits/stdc++.h>
using namespace std; 
const long long N=1e4+9;
long long a[N][N];
long long n,m,k,b[N],d[15],c[15][N],vis[N][N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(long long i=1;i<=m;i++){
		long long u,v,w;
		cin>>u>>v;
		cin>>a[u][v];
		
	}
	for(long long i=1;i<=k;i++){
		cin>>d[i];
		for(long long j=1;j<=n;j++){
			cin>>c[i][j];
		}
	}int ma=0;
	for(long long i=1;i<=n;i++){
		int mi=100000000,mj=0;
		for(long long j=1;j<=n;j++){
			if(i!=j&&vis[i][j]==0&&a[i][j]!=0){
				if(a[i][j]<mi){
					mi=a[i][j];
				}
				mj=j;
			}
			ma+=mi;
			vis[i][mj]=1;
		}
	}cout<<ma;
}
