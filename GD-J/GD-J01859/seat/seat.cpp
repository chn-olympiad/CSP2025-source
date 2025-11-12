#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],x,mi,ind[10][10],fy[4]={0,0,0,1},fx[4]={0,-1,1,0};
void dfs(int x,int y,int k){
	ind[x][y]=k;
	for(int i=1;i<=3;i++){
		int tx=x+fx[i];
		int ty=y+fy[i];
		if(ind[tx][ty]==0 and tx>=1 and tx<=n and ty>=1 and ty<=m) dfs(tx,ty,k+1);
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>x;
	a[1]=x;
	for(int i=2;i<=n*m;i++) cin>>a[i];
	sort(a+1,a+1+n*m);
	reverse(a+1,a+1+n*m);
	for(int i=1;i<=n*m;i++) if(a[i]==x) mi=i;
	
	dfs(1,1,1);
	
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if(ind[i][j]==mi) cout<<j<<' '<<i<<endl;

	return 0; 
} 
