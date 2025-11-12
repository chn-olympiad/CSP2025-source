#include<bits/stdc++.h>
using namespace std;

int n,m,c,r,a[120],k,x,l;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n*m;i++)
	{
		scanf("%d",&a[i]);
	}
	k=a[1];
	sort(a+1,a+(n*m)+1);
	for(int i=n*m,j=1;i>=1;i--,j++)
	{
		if(k==a[i])  x=j;
	}
	l=x%n;
	c=x/n+(l!=0);
	if(c%2!=0)
	{
		if(l==0)  r=n;
		else  r=l;
	}
	else
	{
		if(l==0)  l=n;
		r=n-(l-1);
	}
	printf("%d %d",c,r);
	return 0;
}
