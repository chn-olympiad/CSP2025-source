#include<iostream>
#include<algorithm>
using namespace std;
int n,m,x,t,r;
int a[300];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d%d",&n,&m,&x);
	a[1]=x;
	for (int i=2;i<=n*m;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n*m+1,cmp);
	for (int i=1;i<=n*m;i++)
		if (a[i]==x){
			x=i;
			break;
		}
	t=x/n,r=x%n;
	if (r==0)
		if (t%2==0)
			printf("%d %d",t,1);
		else
			printf("%d %d",t,n);
	else
		if (t%2==0)
			printf("%d %d",t+1,r);
		else
			printf("%d %d",t+1,n-r+1);
	return 0;
}
