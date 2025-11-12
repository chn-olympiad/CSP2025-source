#include<cstdio>
#include<iostream>
using namespace std;
int n,m,s,tot,x;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d%d",&n,&m,&s);
	for(int i=1;i<n*m;i++)
	{
		scanf("%d",&x);
		if(x>s) tot++;
	}
	tot++;
	printf("%d ",(tot-1)/n+1);
	if((tot-1)/n%2==0)
	{
		printf("%d\n",(tot-1)%n+1);
	}
	else
	{
		printf("%d\n",n-(tot-1)%n);
	}
}
/*
3 3
94 95 96 97 98 99 100 93 92
*/
