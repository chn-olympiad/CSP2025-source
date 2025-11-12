#include<bits/stdc++.h>
using namespace std;
int n,m,c,r;
int a[105],b;
int vis[12][12];
bool cmp(int a,int b){
	return a>b;
}
void dfs(int x,int y,int o){
	vis[x][y]=a[o];
	if(vis[x][y]==b){
		c=x,r=y;
		return;
	}
	if(vis[x+1][y]==0&&x+1>=1&&x+1<=n){
		dfs(x+1,y,o+1);
	}
	else if(vis[x-1][y]==0&&x-1>=1&&x-1<=n){
		dfs(x-1,y,o+1);
	}else if(vis[x][y+1]==0&&y+1>=1&&y+1<=m){
		dfs(x,y+1,o+1);
	}
	
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	b=a[1];
	sort(a+1,a+n*m+1,cmp);
	dfs(1,1,1);
//	for(int i=1;i<=n*m;i++){
//		cout<<a[i]<<" ";
//	}
	cout<<r<<" "<<c;
	return 0;
}
