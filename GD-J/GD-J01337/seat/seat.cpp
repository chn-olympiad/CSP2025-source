#include<bits/stdc++.h>
using namespace std;
int n,m,o;
int a[1001];
void fun(int x,int y,int b,int c){
	if(a[c]==o) {
		printf("%d %d",x,y);
		return;
	}
	if(b==0){
		if(y==n) return fun(x+1,y,1,c+1);
		return fun(x,y+1,0,c+1);
	}
	else{
		if(y==1) return fun(x+1,y,0,c+1);
		return fun(x,y-1,1,c+1);
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++) scanf("%d",&a[i]);
	o=a[1];
	sort(a+1,a+1+n*m,greater<int>());
	fun(1,1,0,1);

	return 0;
}

