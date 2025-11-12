#include<bits/stdc++.h>
using namespace std; 
int n,m,mc=1;//行 列 名次 
int dx[]={1,0,-1,0};//蛇形分配
int dy[]={0,1,0,1};
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	scanf("%D%D",&n,&m);
	int a;
	scanf("%D",&a);
	for(int i=2;i<=n*m;i++){
		int x;
		scanf("%d",&x);
		if(x>a) mc++;
	} 
	// xr 是第几名
	int tx=0,ty=0,x=1,y=1,now=0;//临时x 临时y x y 方向 
	for(int i=1;i<=mc-1;i++){
		if(tx==n||ty==m||tx==1) now=(now+1)%4;//换方向 
		tx=x+dx[now];
		ty=y+dy[now];
		x=tx,y=ty;
	}
	// xr 在哪里 
	printf("%d %d",y,x);
	
	return 0; 
} 
/*
3 3
94 95 96 97 98 99 100 93 92
*/
