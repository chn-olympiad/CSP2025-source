#include <bits/stdc++.h>
using namespace std;
int c,r,n,m,a[105],R;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n*m;i++) scanf("%d",&a[i]);
	R=a[1];
	sort(a,a+n*m+1);
	for(int i=1;i<=n*m;i++){
		if(R==a[i]){
			R=n*m-i+1;
			break;
		}
	}
	c=ceil(R*1.0/n*1.0);
	if(c%2==1) r=m-ceil(R*1.0/m*1.0)+1;
	else if(c%2==0) r=ceil(R*1.0/m*1.0);
	printf("%d %d",c,r);
	return 0;
}
