#include<bits/stdc++.h>
using namespace std;
int a[200],s[20][20];
bool vis[20][20];
int n,m,cnt,t;
bool cmp(int x,int y){
	return x>y;
}
bool pd(int x,int y){
	return x>=1&&x<=n&&y>=1&&y<=m&&!vis[x][y];
}
void dfs(int x,int y,int k){
	if(k==t){
		cout<<y<<" "<<x<<"\n";
		return ;
	}
	vis[x][y]=1;
	if(pd(x+1,y)) dfs(x+1,y,k+1);
	else if(pd(x-1,y)) dfs(x-1,y,k+1);
	else dfs(x,y+1,k+1);
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	cnt=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==cnt){
			t=i; break;
		}
	}
	dfs(1,1,1);
	return 0;
}
