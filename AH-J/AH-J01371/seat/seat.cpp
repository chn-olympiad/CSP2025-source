#include <bits/stdc++.h>
using namespace std;
int a[10005],n,m,t=1,x,y,tt;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
		if(a[i]>a[1])t++;
		}
		if(t%n){
	tt=t-t%n;
	x=tt/n+1;
	if(x%2==0)
	y=n-t%n+1;
	else y=t%n;
}
else{
	x=t/n;
	if(x%2==0)
	y=1;
	else y=n;
	}
	
	printf("%d %d",x,y);
return 0;
}
