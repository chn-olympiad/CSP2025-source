#include<bits/stdc++.h>
using namespace std;
int n,m,seat[15][15],nx=1,ny=1,step=1,a[105],r;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
	}
	r=a[1];
	sort(a+1,a+1+n*m,cmp);
	while(step<=n*m){
		seat[nx][ny]=a[step];
		if(a[step]==r){
			printf("%d %d",ny,nx);
			break;
		}
		if(ny%2==0){
			if(nx==1)ny++;
			else nx--;
		}
		else{
			if(nx==n)ny++;
			else nx++;
		}
		step++;
	}
	return 0;
}