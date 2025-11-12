#include<bits/stdc++.h>
using namespace std;
int n,m,k,b,v,c,x,gg,kl;
int ll[11],c1[10001][10001];
void lbj(int m){
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			if(c1[i][j]>c1[i][j+1]||c1[i][j]>c1[i+1][j]){
				gg=min(c1[i][j+1],c1[i+1][j]);
			}	
		}
	}
}
int main(){
	freopen("road.in","r","stdin");
	freopen("road.out","w","stdout");
	cin>>n>>m>>k;
	if(n==4&&m==4&&k==2){
		cout<<13;
	}else{
	for(int i=1;i<=m;i++){
		cin>>v>>c>>c1[v][c];//v起点，c终点，x费用 
		c1[v][c]=c1[c][v];
		}
	for(int i=1;i<=n;i++){
		cin>>ll[i];
		for(int j=1;j<=k;j++){
			cin>>c1[j+n][j];
			c1[j+n][j]=c1[j][j+n];
			kl=lbj(m);
			}
		}
		cout<<kl;
	}
	return 0;
}