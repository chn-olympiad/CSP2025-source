#include<bits/stdc++.h>
using namespace std;
const int N=1e4+20;
int n,m,g[N][N],d[15],t,f[N][N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(g,0x7f,sizeof g);
	memset(f,0x7f,sizeof f);
	cin>>n>>m>>t;
	for(int i=1;i<=m;++i){
		int a,b,c;
		cin>>a>>b>>c;
		g[a][b]=g[b][a]=c;
		g[i][i]=0;
	}for(int i=1;i<=t;++i){
		cin>>d[i];
		for(int j=1;j<=n;++j){
			int x;
			cin>>x;
			g[n+i][j]=g[j][n+i]=x;
		}
	}for(int i=1;i<=n+t;++i)
		for(int j=1;j<=n+t;++j)
			for(int k=1;k<=n+t;++k)
			    f[i][k]=min(f[i][k],g[i][j]+g[j][k]); 
	cout<<f[1][n];
	return 0;
}
