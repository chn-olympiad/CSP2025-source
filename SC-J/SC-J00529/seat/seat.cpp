#include<bits/stdc++.h>
using namespace std;
int n,m;
int c,r,place=1,sum1,sum2;
int a[105];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)
	{
		scanf("%d",&a[i]);
		if(i!=1)place=a[i]>a[1]?place+1:place;
	}
	sum1=place/n;
	sum2=place%n;
	c=sum2?sum1+1:sum1;
	if(sum2==0)r=c%2?n:1;
	else r=c%2?sum2:n-sum2+1;
	printf("%d %d",c,r);
	return 0;
}
/*
2 2
99 100 97 98

3 3
94 95 96 97 98 99 100 93 92
*/