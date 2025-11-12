#include<bits/stdc++.h>
using namespace std;
const int N=10000;
int n,m,k;
int f[N][N];
int u[N];
int v[N];
int w[N][N];
int c[N],a[N][N];
bool s(int n){
	for(int i=1;i<=n;i++){
				if(w[1][i]==1&&w[i][n]==1){
					
				
				return w[1][n]=min(w[1][n],w[1][i]+w[i][n]);
			
		}
		}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i];
		cin>>w[u[i]][v[i]];
		f[u[i]][v[i]]=1;
		f[v[i]][u[i]]=1;
		w[i][i]=0;
		f[i][i]=0;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	if(k==0){
		if(f[1][n]==0){
			w[1][n]=0;
		}
		s(n);
	}
	cout<<w[1][n];
	fclose(stdin);fclose(stdout);
	return 0;
}