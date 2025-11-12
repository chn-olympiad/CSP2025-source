#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e2+10;
int n,a[MAXN*MAXN],m,b[MAXN][MAXN],k,r;
int cmp(int x,int y){
	return x>y;
}
void work(int j,int i,int c){
	for(int z=1;z<=n;z++,i+=c) b[i][j]=a[++k];
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++) scanf("%d",&a[i]);
	r=a[1],sort(a+1,a+1+n*m,cmp);
	for(int j=1;j<=m;j++){
		if(j&1) work(j,1,1);
		else work(j,n,-1);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(r==b[i][j]){
				printf("%d %d",j,i);
				return 0;
			}
		}
	}
	return 0;
} 

