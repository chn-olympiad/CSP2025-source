#include<bits/stdc++.h>
using namespace std;
int a[110];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,R;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
		if(i==1)R=a[1];
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=m;i++){
		if(i&1){
			for(int j=1;j<=n;j++){
				if(a[(i-1)*n+j]==R){
					printf("%d %d",i,j);
					return 0;
				}
			}
		}else{
			for(int j=n;j>=1;j--){
				if(a[(i-1)*n+n-j+1]==R){
					printf("%d %d",i,j);
					return 0;
				}
			}
		}
	}
	return 0;
}
