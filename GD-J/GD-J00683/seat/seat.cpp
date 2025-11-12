#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int n,m,a[101],x,t,s=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
	}
	x=a[1];
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--){
		if(a[i]==x){
			x=n*m-i+1;
		}
	}
	for(int i=1;i<=m;i++){
		if(t==0){
			for(int j=1;j<=n;j++){
				if(s==x){
					printf("%d %d",i,j);
					return 0;
				}
				s++;
			}
			t=1;
		}else{
			for(int j=n;j>=1;j--){
				if(s==x){
					printf("%d %d",i,j);
					return 0;
				}
				s++;
			}
			t=0;
		}
	}
	return 0;
}
