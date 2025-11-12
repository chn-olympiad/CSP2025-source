#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],b;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.in","r",stdin);
	scanf("%d%d%d",&n,&m,&a[1]),b=a[1];
	for(int i=2;i<=n*m;i++) scanf("%d",&a[i]);
	sort(a+1,a+n*m+1);
	int u=lower_bound(a+1,a+n*m+1,b)-a;u=n*m-u+1;
	int l=u/n+(u%n!=0),ys=(u%n==0?n:u%n);
	int h=(l%2==1?ys:n-ys+1);
	printf("%d %d",l,h); 
	return 0;
}
