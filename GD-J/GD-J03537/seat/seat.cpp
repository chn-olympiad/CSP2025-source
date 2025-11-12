#include<cstdio>
#include<iostream>
#include<algorithm>
#define lis PaiMing
using namespace std;

int a[225];

bool cmp(int a,int b){
	return a>b;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n*m; i++){
		scanf("%d",&a[i]);
	}
	
	int poi=a[1],lis=-1;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1; lis==-1 && i<=n*m; i++){
		if(a[i]==poi) lis=i;
	}
	int c=(lis-1)/n+1,r;
	printf("%d ",c);
	if(c%2==0) r=n-lis+(c-1)*n+1;
	else r=1+lis-(c-1)*n-1;
	printf("%d",r);
	
	return 0; //expect: 100 pts
}
