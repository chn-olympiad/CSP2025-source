#include<bits/stdc++.h>
using namespace std;
int n,m,xu,a[105];
void dfs(int x,int y,int c){
	if(a[c]!=xu){
		if(y%2==1){
			if(x<n) dfs(x+1,y,c+1);
			if(x==n) dfs(x,y+1,c+1);
		}
		if(y%2==0){
			if(x>1) dfs(x-1,y,c+1);
			if(x==1) dfs(x,y+1,c+1);
		}
	}
	if(a[c]==xu){
		printf("%d %d",y,x);
		return;
	}
}
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++) scanf("%d",&a[i]);
	xu=a[1];
	sort(a+1,a+1+n*m,cmp);
	dfs(1,1,1);
	return 0;
}
