#include<bits/stdc++.h>
using namespace std;
int n,m,a[105];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
	}
	int x=a[1],p;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==x){
			p=i;
			break;
		}
	}
	int n2=p/n+1;
	if(p%n==0){
		printf("%d %d",n2-1,n);
	}
	else if(n2%2==1){
		printf("%d %d",n2,p%n);
	}
	else{
		printf("%d %d",n2,n-p%n+1);
	}
	return 0;
}
