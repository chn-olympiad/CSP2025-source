#include <bits/stdc++.h>
using namespace std;
int a[105];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int p=a[1],seat;
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>0;i--)
	{
	    if(p==a[i])
	    {
	    	seat=i;
		}
	}
	seat=n*m-seat+1;
	for(int i=1;i<=m;i++)
	{
		if(i%2==1)
		{
			for(int j=1;j<=n;j++)
			{
				if((i-1)*n+j==seat)
				{
					cout<<i<<" "<<j;
					break;
				}
			}
		}
		else
		{
			for(int j=n;j>0;j--)
			{
      		    if((i-1)*n+(n-j+1)==seat)
      			{
					cout<<i<<" "<<j;
					break;
				}
     		}
		}
	}
	return 0;
} 
