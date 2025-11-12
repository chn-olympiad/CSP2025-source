#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],num_1,imart[15][15],x,y;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
		if(!num_1) num_1=a[i]; 
	}
	sort(a+1,a+n*m+1,cmp);
	int c;
	for(int i=1;i<=n*m;i++){
		if(a[i]==num_1){
			c=i;
		}
	}
	int y,x=c/m;x+=c%2==1 ? 1 : 0;
	if(x%2==1){
		y=c%n;
		if(!y) y=n;
	}
	else{
		y=abs(c-(n+1))%n;
		if(!y) y=n;
	}
	printf("%d %d",x,y);
	return 0;
} 
