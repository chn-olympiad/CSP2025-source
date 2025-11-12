#include <bits/stdc++.h>
using namespace std;
int n,m,a[110],R,num,c,r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%d",&R);
	a[R]=1;
	for(int i=1;i<n*m;i++){
		int awa;
		scanf("%d",&awa);
		a[awa]=1;
	}
	for(int i=100;i>=R;i--)
		if(a[i]) num++;
	c=num/n;
	r=num%n;
	if(r) c++;
	if(c%2==1){
		if(r==0) r=n;
	}
	else{
		if(r==0) r=1;
		else r=n+1-r;
	}
	printf("%d %d",c,r);
	return 0;
} 