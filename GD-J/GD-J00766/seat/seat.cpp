#include<bits/stdc++.h>
int c=1,r=1,n,m,a[105],score=0,b[15][15];
bool cmp(int x,int y){
	return x>y;
}
void dfs(int x,int y,int i,int t){
	b[x][y]=a[i];
	if(x==n&&y==m){
		return;
	}
	if(x==1&&y==1){
		dfs(2,1,i+1,t);
	}
	else if((x==1&&t==-1)||(x==n&&t==1)){
		dfs(x,y+1,i+1,t*-1);
	}
	else{
		dfs(x+t,y,i+1,t);
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)
		scanf("%d",&a[i]);
	score=a[1];
	std::sort(a+1,a+n*m+1,cmp);
	dfs(1,1,1,1);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(b[i][j]==score){
				printf("%d %d",j,i);
				return 0;
			}
		}
	}
	return 0;
}
