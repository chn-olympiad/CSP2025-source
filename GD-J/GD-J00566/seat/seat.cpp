#include<bits/stdc++.h>
using namespace std;
int n,m,c,r,qq;
struct u{
	int yee,s;
}a[110];
int cmp(u x,u y){
	return x.s>y.s;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n*m;i++){
		a[i].yee=i;
		scanf("%d",&a[i].s);
	}
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i].yee==1){
			qq=i;
			break;
		}
	}
	if(qq%n){
		c=qq/n+1;
		if(c%2){
			r=qq%n;
		}
		else{
			r=n-qq%n+1;
		}
	}
	else{
		c=qq/n;
		if(c%2){
			r=n;
		}
		else{
			r=1;
		}
	}
	printf("%d %d",c,r);
	return 0;
}
