#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stkdin);
	freopen("seat.out","w",stdout);
	int n,m,a[11][11]={0},r;
	scanf("%d %d",&m,&n);int m1,n1;n1=1;m1=1;
	int dx[]={0,1,0,1};
	int dy[]={1,0,-1,0};int d=0;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
			r=a[1][1];
			if(a[i][j]>r){
				if(m1+dx[d]>m||m1+dx[d]<1||n1+dy[d]>n){
					d=(d+1)%4;
				}
				m1+=dx[d];n1+=dy[d];
			}
		}
	}
	printf("%d %d",m1,n1);
	return 0;
}
