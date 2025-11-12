#include<bits/stdc++.h>
using namespace std;
int a[1005];
int sit[1005][1005];
bool vis[1005][1005];
int dx[4]={1,0,0,0};
int dy[4]={0,0,1,-1};
int n,m;
int x,y,r;
void dfs(int x,int y)
{
	if(sit[x][y]==r){
		cout<<x<<" "<<y;
	}
	for(int i=0;i<=3;i++){
		int ny=y+dy[i],nx;
		if(x>=n)nx=x+dx[i];
		if(nx<1||nx>n||ny<1||ny>m)continue;
		if(vis[nx][ny])continue;
		vis[nx][ny]=1;
		dfs(nx,ny);
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>a[i];
		}
	}
	r=a[1];
	for(int i=1;i<=n*m;i++){
		for(int j=1;j<i;j++){
			if(a[i]<a[j]){
				int y=a[j];
				a[j]=a[i];
				a[i]=y;
		}
	}
}
for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)
	{
			if(sit[i][j]==a[1])
			{
				x=i;
				y=j;
			}
		}
}
dfs(x,y);
				
	fclose(stdin);
	fclose(stdout);
	return 0;
}
