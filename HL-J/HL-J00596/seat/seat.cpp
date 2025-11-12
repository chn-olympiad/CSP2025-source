#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
int r;
int j=0;
int vis[15][15];
int dy[2]={1,-1};
bool flag=1;
int nx=1,ny=1;
void dfs(int x,int y,int z){
	if(z==r){
		cout<<x<<" "<<y;
		return ;
	}
	for(int i=0;i<2;i++){
		if(y==n&&flag||flag&&x!=1&&y==1){
			nx+=1;
			flag=0;
		}
		else if(x%2==0){
			ny=dy[1]+y;
			flag=1;
		}
		else {
			ny =dy[0]+y;
			flag=1;
		}
		if(nx>0&&nx<=m&&ny>0&&ny<=n&&vis[nx][ny]==0){
			vis[nx][ny]=1;
			dfs(nx,ny,a[++j]);
		}
	}
}
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	r=a[0];
	sort(a,a+n*m,cmp);
	vis[1][1]=1;
	dfs(1,1,a[0]);
	return 0;
}


