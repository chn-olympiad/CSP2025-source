#include<iostream>
#include<cstdio>
using namespace std;
int n,m;
int a[105],cnt;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
		if(i>1&&a[i]>a[1])cnt++;
	}
	int x,y;
	x=cnt/n+1;
	y=cnt-(x*n-n);
	if(x%2==1){
		y=y+1;
	}else{
		y=n-y;
	}
	printf("%d %d",x,y);
	return 0;
}//I like yuanshen!!!
