#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,arr[10000],b,d,e,c;
	d = 0;
	scanf("%d %d",&n,&m);
	for(int i = 0;i<n*m;i++)
	{
		scanf("%d",&arr[i]);
	}
	b = arr[0];
	for(int i = 0;i<n*m;i++)
	{
		if(arr[i]<arr[i+1])
		{
			c=arr[i];
			arr[i] = arr[i+1];
			arr[i+1] = c;
		}
	}
	c = 1;
	for(int i = 0;i<n*m;i++)
	{
		if(b==arr[i])
		{
			c = 0;
			d++;
		}
		if(c!=0)
		{
			d++;
		}
	}
	if(d%n==0)
	{
		e = d/n;
	}
	else
	{
		e = d/n+1;
	}
	if(e%2==0)
	{
		e-=1;
		d-=(e*n)-1;
		e+=1;
	}
	else
	{
		e-=1;
		d-=e*n;
		e+=1;
	}
	printf("%d %d",e,d);
}
