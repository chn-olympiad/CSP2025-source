#include"bits/stdc++.h"
using namespace std;
const int N=110;
int n,m,a[N],r,w,x;
int cmp(int x,int y){return x>y;}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)cin>>a[i];
	r=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==r){
			w=i;
			break;
		}
	}
	if(w%n)x=w/n+1;
	else x=w/n;
	printf("%d ",x);
	if(x&1){
		if(w%n==0)printf("%d",n);
		else printf("%d",w%n);
	}
	else {
		if(w%n==0)printf("%d",1);
		else printf("%d",n-(w%n)+1);
	}
	return 0;
} 
