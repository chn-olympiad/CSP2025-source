#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long x,y;
	cin>>x>>y;
	long long a[x*y+10];
	for(int i=1;i<=x*y;i++)
		cin>>a[i];
	long long R=a[1];
	for(int i=1;i<=x*y;i++)
	{
		for(int j=1;j<=x*y;j++)
		{
			if(a[j]<a[j+1])
			swap(a[j],a[j+1]);
		}
	}
	
	if(R==a[1])
	{
		cout<<1<<" "<<1;
		return 0;
	}
	long long q=1;
	for(int i=1;i<=y;i++)
	{
		if(i%2==0)
		{
			for(int j=x;j>=1;j--)
			{
				if(R==a[q])
				{
					cout<<i<<" "<<j;
					return 0;
				}
				q++;
			}
		}
		if(i%2!=0)
		{
			for(int j=1;j<=x;j++)
			{
				if(R==a[q])
				{
					cout<<i<<" "<<j;
					return 0;
				}
				q++;
			}
		}
	}
	return 0;
}
