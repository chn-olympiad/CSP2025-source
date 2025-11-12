#include<bits/stdc++.h>
using namespace std;
int n,m,k,a[10010][10010],d[4][2]={{1,0},{0,1},{0,-1},{-1,0}},xc[100010],v[10010][10010],ans=0x3f3f3f3f;
void dfs(int x,int y,int sum,int wk,int fa){
	v[x][y]=1;
	if(wk-fa==n){
		ans=min(ans,sum);
	}
	for(int i=1;i<=n;i++){
		int nx=x+d[i][0],ny=y+d[i][1];
		if(nx>=1 && nx<=n && ny>=1 && ny<=n && v[nx][ny]==0){
			v[nx][ny]=1;
			sum+=a[nx][ny];
			dfs(nx,ny,sum,wk+1,fa);
		}else if(((nx>=n && nx<=n+k&&ny>=1 &&ny<=n)||(nx>=n && nx<=n&&ny>=n &&ny<=n+k))&&v[nx][ny]==0){
			v[nx][ny]=1;
			sum+=a[nx][ny];
			sum+=max(xc[nx],xc[ny]);
			dfs(nx,ny,sum,wk+1,fa+1);
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
		a[x][y]=z;
		a[y][x]=z;
	}
	for(int i=1;i<=k;i++){
		int x,y;
		cin>>xc[n+i];
		for(int j=1;j<=n;j++){
			cin>>y;
			a[n+i][j]=y;
			a[j][n+i]=y;
		}
	} 
	dfs(1,1,0,0,0);
	cout<<ans<<endl;
	return 0;
}
