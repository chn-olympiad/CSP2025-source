#include <bits/stdc++.h>
using namespace std;
int s[10010][10010];
int n,m,k,x,y;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(s,0x3f,sizeof(s));
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		s[u][v]=min(s[u][v],w); s[v][u]=s[u][v];
	} 
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(j!=i && s[i][j]==0x3f3f3f3f)
				x=i,y=j;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(j!=i){
				for(int k=1;k<=n;k++)
					s[i][j]=s[j][i]=min(s[i][j],s[i][k]+s[k][j]);
			}
		}
	} 
	cout<<s[x][y];
	return 0;
}
