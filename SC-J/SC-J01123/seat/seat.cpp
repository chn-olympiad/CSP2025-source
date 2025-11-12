#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000],b[20][20],x=0,y=1,q,top=0; 
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	q=a[1];
	sort(a+1,a+n*m+1,cmp);
	while(1){
		while(x+1<=n){
			x++;
			b[x][y]=a[++top];
		}
		if(y+1<=m){
			y++;
			b[x][y]=a[++top];
		}else{
			break;
		}
		while(x-1>=1){
			x--;
			b[x][y]=a[++top];
		}
		if(y+1<=m){
			y++;
			b[x][y]=a[++top];
		}else{
			break;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(b[i][j]==q){
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
	return 0;
}
/*
排序
100 99 98 97
先向下走直到走不动
100
99
在向右一格走不动就推出 
100
99 98
先向下走直到走不动
100 97
99 98
在向右一格如果走不动就推出 
输出 
1 2 
*/