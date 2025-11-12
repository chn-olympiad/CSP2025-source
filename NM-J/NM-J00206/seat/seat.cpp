#include <bits/stdc++.h>
using namespace std;
int x,y;
int a[1000],b[11][11];
void dfs(int xx,int z){
	if(xx>=x*y){
		return;
	}
	if(z%2==0){
		for(int i=0;i<x;i++){
			b[i][z]=a[xx];
			xx++;
		}
		dfs(xx,z+1); 
	}
	else{
		for(int i=x-1,k=0;i>=0;i--,k++){
			b[i][z]=a[xx];
			xx++;
		}
		dfs(xx,z+1); 
	}
}
int l(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&x,&y);
	for(int i=0;i<x*y;i++){
		scanf("%d",&a[i]);
	}
	int jj=a[0];
	sort(a,a+x*y,l);
	dfs(0,0);
	for(int i=0;i<x;i++){
		for(int j=0;j<y;j++){
			if(b[i][j]==jj){
				printf("%d %d",j+1,i+1);
				return 0;
			}
		}
	}
	return 0;
}
