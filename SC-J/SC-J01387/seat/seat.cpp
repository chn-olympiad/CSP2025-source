#include<bits/stdc++.h>
using namespace std;

int m,n;

int a[105],seat[15][15];
int x,y,nx,ny,a1;

bool comp(int x,int y){
	return x>y;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;++i)  cin>>a[i];
	a1=a[1];
	sort(a+1,a+m*n+1,comp);
	x=0;y=1;
	nx=1;ny=0;
	for(int i=1;i<=n*m;++i){
		x+=nx;
		y+=ny;
		if(a[i]==a1){
			cout<<y<<' '<<x;
            return 0;
		}
		seat[x][y]=a[i];
		if(x==n){
			if(y%2==1){
				nx=0;ny=1;
			}else{
				nx=-1;ny=0;
			}
		}else if(x==1){
			if(y%2==1){
				nx=1;ny=0;
			}else{
				nx=0;ny=1;
			}
		}
	}
	return 0;
}