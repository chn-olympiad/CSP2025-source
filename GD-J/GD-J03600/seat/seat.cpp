#include<bits/stdc++.h>
using namespace std;
int n,m,a[1001],g[1001][1001],cnt=0;
void dfs(int i,int x,int y,string fx){
	if(i>n*m)return;
	g[y][x]=a[i];
	if(g[y][x]==cnt){
		cout<<x<<' '<<y<<'\n';
		return;
	}
	if(y==1&&fx=="up"){
		fx="down";
		x++;
	}else if(y==n&&fx=="down"){
		fx="up";
		x++;
	}else if(fx=="down"){
		y++;
	}else if(fx=="up"){
		y--;
	}
	dfs(i+1,x,y,fx);
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	cnt=a[1];
	sort(a+1,a+1+n*m,greater<int>());
	dfs(1,1,1,"down");
	return 0;
}
