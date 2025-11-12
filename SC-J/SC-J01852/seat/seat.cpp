#include<bits/stdc++.h>
using  namespace std;
int n,m,a[105],r;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)
	{
		scanf("%d",&a[i]);
	}
	r=a[1];
	sort(a,a+n*m+1);
	for(int i=m*n;i>0;i--)
	{
		if(a[i]==r)
		{
			r=n*m-i+1;
			break;
		}
		 
	}
	int s=r/n;
	if(r%n==0)
	{
		printf("%d",s);
		if(s%2==0)
		{
			printf(" %d",1); 
		}
		else
		{
			printf(" %d",n);
		}
	}
	else
	{
		printf("%d",s+1);
		if((s+1)%2==0)
		{
			printf(" %d",n-r+s*n+1); 
		}
		else
		{
			printf(" %d",r-s*n);
		}
	}
	return 0;
}