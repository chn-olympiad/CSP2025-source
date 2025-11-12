#include <bits/stdc++.h>
using namespace std;
int n,m,x,y,t=1,l,h;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%d",&x);
	for(int i=2;i<=m*n;i++)
	{
		scanf("%d",&y);
		if(y>x) t++;
	}
	l=ceil(t*1.0/n);
	if(l%2==0)
	{
		if(t%n==0) h=1;
		else h=n-t%n+1;
	}else
	{
		if(t%n==0) h=n;
		else h=t%n;
	}
	printf("%d %d",l,h);
	return 0;
}