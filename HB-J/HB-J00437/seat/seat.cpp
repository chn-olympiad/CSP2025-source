#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],v[15][15];
int x11=1,y11=1,f;
void dfs(int x,int y,int dp){
	v[x][y]=1;
	if(dp==f){
		x11=x;
		y11=y;
		return;
	}
	if(x+1<=n&&v[x+1][y]==0)dfs(x+1,y,++dp);
	else if(x-1>=1&&v[x-1][y]==0)dfs(x-1,y,++dp);
	else if(y+1<=m&&v[x][y+1]==0)dfs(x,y+1,++dp);
}
bool com(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
	}
	f=a[1];
	int sum=n*m;
	sort(a+1,a+1+sum,com);
	for(int i=1;i<=n*m;i++){
		if(a[i]==f){
			f=i;
			break;
		}
	}
	
	dfs(x11,y11,1);
	cout<<y11<<" "<<x11;
	return 0;
}
