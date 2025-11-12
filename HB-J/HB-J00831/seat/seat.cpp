#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],s[15][15],ans;
bool cmp(int x,int y){
	return x>y;
}
void dfs(int x,int y,int id,bool bj){
	s[x][y]=a[id];
	if(id==n*m) return ;
	if(bj==1&&x==1&&y!=m) dfs(x,y+1,id+1,0);
	else if(bj==0&&x==n&&y!=m) dfs(x,y+1,id+1,1);
	else if(bj==1) dfs(x-1,y,id+1,1);
	else if(bj==0) dfs(x+1,y,id+1,0);
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	ans=a[1];
	stable_sort(a+1,a+1+(n*m),cmp);
	dfs(1,1,1,0);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s[i][j]==ans){
				cout<<j<<" "<<i;
				break;
			}
		}
	}
	return 0;
}
