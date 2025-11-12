#include<bits/stdc++.h>
using namespace std;
int n,m,x;
int a[105];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
	}
	x=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==x){
			if(((i-1)/n)%2==0){
				printf("%d %d",(i-1)/n+1,(i-1)%n+1);
			}else{
				printf("%d %d",(i-1)/n+1,n-(i-1)%n);
			}
		}
	}
	return 0;
}

