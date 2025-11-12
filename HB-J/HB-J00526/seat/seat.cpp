#include<bits/stdc++.h>
using namespace std;
int n,m,k,f=0,ans=1,p[105],a[15][15],b[15][15];
int d[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
bool cmp(int a,int b){
	if(a>b) return 1;
	return 0;
}
void dfs(int x,int y){
	if(f==1) return;
	if(a[x][y]==k){
		f=1;
		cout<<y<<' '<<x;
	}
	for(int i=1;i<=4;i++){
		int tx=x+d[i-1][0],ty=y+d[i-1][1];
//		cout<<d[i][0]<<"  "<<d[i][1]<<"r34e\n";
		if(tx<1||tx>n||ty<1||ty>m||b[tx][ty]==1) continue;
//		cout<<tx<<"  "<<ty<<"rtre\n";
		a[tx][ty]=p[ans];
		b[tx][ty]=1;
		ans++;
		dfs(tx,ty);
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>m>>n;
	for(int i=1;i<=n*m;i++){
		cin>>p[i];
	}
	k=p[1];
	sort(p+1,p+n*m+1,cmp);
	a[1][1]=p[1];
	dfs(0,1);
/*	cout<<ans<<endl;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cout<<a[i][j]<<' ';
		}
		cout<<'\n';
	}*/
	return 0;
}
