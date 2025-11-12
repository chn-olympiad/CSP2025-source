#include<bits/stdc++.h>
using namespace std;
const int N=15;
int a[N][N];
int n,m,c,r,cnt,tidx;
struct Node{
	int w,idx;
}b[1000];
bool cmp(Node x,Node y){
	return x.w>y.w;
}
int main(){
//	freopen("seat3.in","r",stdin);
//	freopen("seat1.out","w",stdout);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&a[i][j]);
			b[++cnt].w=a[i][j];
			b[cnt].idx=cnt;
		}
	}
	sort(b+1,b+1+cnt,cmp);
	for(int i=1;i<=cnt;i++){
		if(b[i].idx==1){
			tidx=i;
			break;
		}
	}
//	if(tidx%n==0){
//		c=tidx/n;
//	}else{
//		c=tidx/n+1;
//	}
	c=(tidx+n-1)/n;
	int t=tidx-(c-1)*n;
	if(c%2==0){
		r=n-t+1;
	}else{
		r=t;
	}
	printf("%d %d",c,r);
	return 0;
}
