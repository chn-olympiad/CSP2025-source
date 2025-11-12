#include<bits/stdc++.h>
using namespace std;

const int MAXN=110;

int n,m;
int a[MAXN];
int R,c=-1,r=-1;

void dfs(int n1, int m1, int ji,int f_x){//f_x:fang_xiang 1--向下 2--向上 
	if(c!=-1&&r!=-1) return;
	if(f_x==1) {
		if(a[ji]==R){
			c=m1;
			r=n1;
			return;
		}else{
			if(n1==n){
				dfs(n1,m1+1,ji+1,2);
			}else{
				dfs(n1+1,m1,ji+1,1);
			}
		}
	}else{
		if(a[ji]==R){
			c=m1;
			r=n1;
			return;
		}else{
			if(n1==1){
				dfs(n1,m1+1,ji+1,1);
			}else{
				dfs(n1-1,m1,ji+1,2);
			}
		}		
	}
}

bool cmp(int x,int y){
	return x>y;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]); 
	} 
	R=a[1];
	sort(a+1,a+1+n*m,cmp);
	dfs(1,1,1,1);
	printf("%d %d",c,r); 
	return 0;
}
