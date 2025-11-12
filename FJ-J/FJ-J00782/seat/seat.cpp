#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000010],x,num,xx,yy;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
	}
	x=a[1];
	sort(a+1,a+1+n*m);
	num=lower_bound(a+1,a+1+n*m,x)-a;
	num=n*m-num+1;
	xx=(num-1)/n+1;
	yy=(num-1)%n+1;
	if(xx%2==0){
		yy=n-yy+1;
	}
	printf("%d %d",xx,yy);
	return 0;
}
