#include<bits/stdc++.h>
using namespace std;
int a[1001],mp[12][12],cnt=0,n,m,xr;
bool vis[12][12];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int dfs(int x,int y){
	vis[x][y]=1;
	mp[x][y]=a[cnt++];
	if(mp[x][y]==xr){
		cout<<y<<' '<<x; 
	}
	cout<<y<<' '<<x<<endl;
	for(int i=0;i<4;i++){
		int nx=dx[i]+x;
		int ny=dy[i]+y;
		if(nx>0&&nx<=n&&ny>0&&ny<=m&&!vis[nx][ny]){
			dfs(nx,ny);
			//cout<<1;
		}
	}
}
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	xr=a[0];
	int temp=n*m;
	sort(a,a+temp,cmp);
	//cout<<xr;
	dfs(1,1);
	return 0;	
} 
