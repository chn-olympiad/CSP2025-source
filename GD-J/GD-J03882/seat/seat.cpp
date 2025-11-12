#include<bits/stdc++.h>
using namespace std;
int n,m;
int read(){
	int t;
	scanf("%d",&t);
	return t;
}
struct Test{
	int n;
	int t;
} a[105],s[10][10];
bool cmp(Test x,Test y){
	return x.t>y.t;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n*m;i++){
		a[i].n=i;
		a[i].t=read();
	}
	sort(a+1,a+n*m+1,cmp);
	int p=1;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				if(a[p++].n==1){
					printf("%d %d",i,j);
					return 0;
				}
			}
		}
		else{
			for(int j=n;j>=1;j--){
				if(a[p++].n==1){
					printf("%d %d",i,j);
					return 0;
				}
			}
		}
	}
	return 0;
}
