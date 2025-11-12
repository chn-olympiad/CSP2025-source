#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],mp[15][15],cnt;
void dfs(int x,int y){
	if(x>=m+1||y>=n+1){
		return ;
	}
	mp[x][y]=a[++cnt];
	if(y==n&&x%2==1){
		dfs(x+1,n);
		return ;
	}
	else if(y==1&&x%2==0){
		dfs(x+1,1);
		return ;
	}
	else if(x%2==1){
		dfs(x,y+1);
		return ;
	}
	else if(x%2==0){
		dfs(x,y-1);
		return ;
	}
	return ;
}
bool cmp(int i,int j){
	return i>j;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int R=a[1];
	sort(a+1,a+n*m+1,cmp);
	dfs(1,1);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(mp[i][j]==R){
				cout<<i<<" "<<j;
				return 0;
			}
		}
	}
	return 0;
}