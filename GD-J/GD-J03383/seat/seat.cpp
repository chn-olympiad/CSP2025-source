#include<bits/stdc++.h>
using namespace std;
int n, m, N, a[110], x, y, num;

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d %d",&n,&m);
	N=n*m;
	for(int i=1;i<=N;i++)
	{
		scanf("%d",&a[i]);
	}
	x=a[1];
	sort(a+1,a+1+N);
	
	for(int i=1;i<=N;i++)
	{
		if(a[i]==x)
		{
			num=i;
			break;
		}
	}
	num=N-num+1;
	
	if(num%n==0)
	{
		x=n, y=num/n;
	}
	else
	{
		x=num%n, y=num/n+1;
	}
	
	if(y%2==0)
	{
		x=n-x+1;
	}
	
	printf("%d %d",y,x);
	return 0;
 } 
