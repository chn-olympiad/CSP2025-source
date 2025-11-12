#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int n,m,ar,seat[15][15],a[110],endx,endy;
void dfs(int x,int y,int p,bool wh){
//	cout<<x<<" "<<y<<endl;
	seat[x][y]=a[p];
	if(x==endx&&y==endy){
		return;
	}if(p%n==0){
		dfs(x,y+1,p+1,!wh);
	}else if(!wh)dfs(x+1,y,p+1,wh);
	else dfs(x-1,y,p+1,wh);
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	endy=m;
	if(m%2==0){
		endx=1;
	}else{
		endx=n;
	}
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	ar=a[1];
	sort(a+1,a+n*m+1,greater<int>());
//	for(int i=1;i<=n*m;i++){
//		cout<<a[i]<<" ";
//	}
	dfs(1,1,1,0);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(seat[i][j]==ar){
				printf("%d %d",j,i);
				return 0;
			}
//			cout<<seat[i][j]<<" ";
		}
	}
	return 0;
} 
