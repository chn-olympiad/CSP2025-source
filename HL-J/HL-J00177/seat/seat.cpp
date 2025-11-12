#include<bits/stdc++.h>
using namespace std;
int n,m,a[120];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)
		scanf("%d",&a[i]);
	int x=a[1];
	sort(a+1,a+(m*n)+1,cmp);
	int xid;
	for(int i=1;i<=n*m;i++){
		if(a[i]==x){
			xid=i;
			break;
		}
	}
	if(xid%n==0){
		printf("%d ",xid/n);
		int xl=xid/n;
		if(xl%2==0){
			printf("%d",1);
		}else
			printf("%d",n);
	}	
	else{
		printf("%d ",xid/n+1);
		int xl=xid/n+1;
		if(xl%2==0){
			printf("%d",n-xid%n+1);
		}else
			printf("%d",xid%n);
	}
}

