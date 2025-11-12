#include <bits/stdc++.h>
using namespace std;
int s[101];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,p,z=0,x,y;
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n*m;i++)
	{
		scanf("%d",&s[i]);
	}
	p=s[1];
	sort(s+1,s+n*m+1,cmp);
	for (int i=1;i<=n*m;i++)
	{
		if (s[i]==p)
		{
			z=i;
			break;
		}
	}
	y=z%n;
	if (y==0)
	x=z/n;
	else 
	x=z/n+1;
	printf("%d ",x);
	if (x%2==1)
	{
		if (y==0)
		printf("%d",n);
		else 
		printf("%d",y);
	}
	else 
	{
		if (y==0)
		printf("1");
		else 
		printf("%d",n-y+1);
	}
	return 0;
}
