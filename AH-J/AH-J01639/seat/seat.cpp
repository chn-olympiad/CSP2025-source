//seat.cpp
#include<bits/stdc++.h>
using namespace std;
int m,n,a[110];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	int num=n*m;
	for(int i=1;i<=num;i++)
		scanf("%d",&a[i]);
	int xr=a[1];
	sort(a+1,a+1+num,cmp);//cmp
	for(int i=1;i<=num;i++)
		if(a[i]==xr) {xr=i;break;}
	int rx,ry;
	rx=ceil(xr*1.0/n);
	if(rx%2==0) ry=n-(xr%n)+1;
	else ry=xr%n;
	if(ry==0) ry=n;
	printf("%d %d",rx,ry);
	return 0;
}
