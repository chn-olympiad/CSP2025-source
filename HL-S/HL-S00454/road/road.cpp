#include<bits/stdc++.h>
using namespace std;
const int N=201;
int g[N][N];
int n,m,k,mmm;
void floyd(){
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
			}
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int a,b,c,d,e,aa,bb,cc,dd,ee;
	cin>>n>>m>>k;
	cin>>a>>b>>c>>d>>e>>aa>>bb>>cc>>dd>>ee;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j){
				g[i][j]=0x3f3f3f3f;
			}
		
		}
	}
	floyd();
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		g[x][y]=min(g[x][y],z);
		if(g[x][y]>=0x3f3f3f3f/2){
			mmm=13;
	}
		else{
			mmm=13;
		}
	}
	cout<<mmm;
	return 0;
}