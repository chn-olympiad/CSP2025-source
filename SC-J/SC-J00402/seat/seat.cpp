#include<bits/stdc++.h>
using namespace std;
int xn[5] = {0,1,0,-1};
int ya[5] = {0,0,1,0};
int n,m;
int a[101];
int ma[101][101];
bool cmp(int a,int b){
	return a>b;
}
int dfs(int x,int y,int k){
	if(x>n || y>m)return 0;
	if(x == n && y%2 == 1){
		ma[x][y] = a[k];
		int nx = x+xn[2];
		int ny = y+ya[2];
		dfs(nx,ny,k+1);
	}
	else if(x == 1 && y%2 == 0){
		ma[x][y] = a[k];
		int nx = x+xn[2];
		int ny = y+ya[2];
		dfs(nx,ny,k+1);
	}
	else if(y%2 ==1){
		ma[x][y] = a[k];
		int nx = x+xn[1];
		int ny = y+ya[1];
		dfs(nx,ny,k+1);
	}else {
		ma[x][y] = a[k];
		int nx = x+xn[3];
		int ny = y+ya[3];
		dfs(nx,ny,k+1);
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n*m;i++){
		cin>>a[i];
	}
	int ans = a[1];
	sort(a+1,a+1+n*m,cmp);
	ma[1][1] = a[1];
	dfs(1,1,1);
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=m;j++){
			if(ma[i][j] == ans)cout<<j<<' '<<i;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 