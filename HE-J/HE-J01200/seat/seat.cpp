#include<bits/stdc++.h>
using namespace std;
int a[1005],n,m,c,r;
int main()
{
	fropen("seat.in","r",stdin);
	fropen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(n>=1)
		{
			c=n-1;
		}
		if(n<=10)
		{
			r=n+1;
		}
		if(a[1]>=100)
		{
		   c=1;
		   r=1;
		}
		if(a[1]<=99)
		{
			c=1;
			r=2;
		}
 }
	for(int i=1;i<=m;i++)
	{
		if(m>=1)
		{
			c=m-1;
		}
		if(m<=10)
		{
			r=m+1;
		}
		if(a[1]>=100)
		{
		   c=1;
		   r=1;
		}
		if(a[1]<=99)
		{
			c=1;
			r=2;
		}

	}  
	cout<<c<<" "<<r;
    return 0;
	fclose(stdin);
	fclose(stdout);
}
