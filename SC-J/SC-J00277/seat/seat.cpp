#include<bits/stdc++.h>
using namespace std;
string s;
int x,y,tot;
int a[1000050];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>x>>y;
	for(int i=1;i<=x*y;i++)
	{
		cin>>a[i];
		if(i==1)
		tot=a[i];
		for(int j=1;j<=i;j++)
		{
			if(a[j]<a[i])
			swap(a[j],a[i]);
		}
	}
	int z=0;
	for(int i=1;i<=x;i++)
	{
		if(i%2==1)
		{
			for(int j=1;j<=y;j++)
			{
				z++;
				if(a[z]==tot)
				{
					cout<<i<<" "<<j;
					return 0;
				}
			}	
		}
		else	if(i%2==0)
		{
			for(int j=y;j>=1;j--)
			{
				z++;
				if(a[z]==tot)
				{
					cout<<i<<" "<<j;
					return 0;
				}
			}	
		}
	}
	return 0;
}