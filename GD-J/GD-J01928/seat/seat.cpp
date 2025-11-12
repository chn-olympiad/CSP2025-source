#include<iostream>
#include<cstdio>
using namespace std;
const int N=110;
int n,m,a[N],rk=1,h,l;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]>a[1]) rk++;
	}
	l=rk/n+1;
	if(rk%n==0) l--;
	if(l%2==1) 
	{
		h=rk%n;
		if(!h) h=m;
	}
	else 
	{
		h=n-rk%n+1;
		if(rk%n==0) h=1;
	}
	printf("%d %d",l,h);
	return 0;
}
