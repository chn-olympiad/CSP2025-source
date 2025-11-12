#include<bits/stdc++.h>
using namespace std;
int a[1000];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n;
	cin>>n>>m;
	for(int i=0;i<n*m;i++)
	{
		cin>>a[i];
	}
	int b=a[0];

	sort(a,a+m*n);
	
	int cnt=0;
	for(int i=n*m-1;i>=0;i--)
	{
		cnt++;
		
		if(a[i]==b)
		{
			b=cnt;
			break;
		}
	}
	int x1,y1;
	if(b%n==0)
	{
		x1=b/n;
		if(x1%2!=0)
		{
			y1=n;
		}
		else
		{
			y1=1;
		}
	}
	else if(n==2)
	{
		if(b%n==0)
		{
			x1=b%n;
			if(x1%2!=0)
			{
				y1=n;
			}
			else
			{
				y1=1;
			}
		}
		else
		{
			x1=b%n+1;
			if(x1%2!=0)
			{
				y1=1;
			}
			else
			{
				y1=n;
			}
		}
		
	}
	else
	{
		x1=b/n+1;
		if(x1%2!=0)
		{
			y1=b%n;
		}
		else
		{
			y1=n-(b%n);
		}
	}
	cout<<x1<<" "<<y1;
    fclose(stdin);
	fclose(stdout);
	return 0;
}