#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int x,y,a[10001],seat[1001][1001];
	cin>>x>>y;
	for(int i=1;i<=x*y;i++)
	{
		cin>>a[i];
	}
	int n=a[1];
	sort(a+1,a+1+x*y);
	int wei=x*y;
	for(int i=1;i<=y;i++)
	{
		if(i%2==1)
		{
			for(int j=1;j<=x;j++)
			{
				seat[j][i]=a[wei];
				wei--;
				if(seat[j][i]==n)
				{
					cout<<i<<' '<<j<<endl;
					return 0;
				}
			}
		}
		else
		{
			for(int j=x;j>=1;j--)
			{
				seat[j][i]=a[wei];
				wei--;
				if(seat[j][i]==n)
				{
					cout<<i<<' '<<j<<endl;
					return 0;
				}
			}
		}
	}
	return 0;
}
