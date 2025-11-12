#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105],t;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&a[i*n+j-n]);
		}
	}t=a[1];
	sort(a+1,a+n*m+1,cmp);
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(i&1){
			for(int j=1;j<=m;j++){
				++cnt;
				if(a[cnt]==t){
					printf("%d %d\n",i,j);
					return 0;
				}
			}
		}else{
			for(int j=m;j>=1;j--){
				++cnt;
				if(a[cnt]==t){
					printf("%d %d\n",i,j);
					return 0;
				}
			}
		}
	}
}