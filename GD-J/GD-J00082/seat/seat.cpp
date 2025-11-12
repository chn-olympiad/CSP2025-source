#include<bits/stdc++.h>
using namespace std;
int n,m,k,a[105],b[15][15],t=0;
bool cmp(int x,int y){return x>y;}
void dfs(int x,int y){
	b[x][y]=a[++t];
	if(y==m && ((m%2==0 && x==1) || (m%2==1 && x==n))) return;
	if(y%2==1){
		if(x!=n) dfs(x+1,y);
		else dfs(x,y+1);
	}
	else{
		if(x!=1) dfs(x-1,y);
		else dfs(x,y+1);
	}
}
signed main(){
	std::ios_base::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >>n>>m;
	for(int i=1;i<=n*m;i++) cin >>a[i];
	k=a[1],sort(a+1,a+n*m+1,cmp);
	dfs(1,1);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(b[i][j]==k){cout<<j<<" "<<i;return 0;}
		}
	}
	return 0;
}
