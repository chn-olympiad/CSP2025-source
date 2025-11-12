#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a[105];
	int n,m;
	cin>>n>>m;
	int r;
	for(int i=0;i<n*m;i++)
	{
		cin>>a[i];
	}
	r=a[0];
	sort(a,a+n*m,cmp);
	int c=0;
	for(int i=1;i<=m;i++)
	{
		if(i%2==1)
		{
			for(int j=1;j<=n;j++)
			{
				if(a[c]==r)
				{
					cout<<i<<' '<<j;
					return 0;
				}
				c++;
			}
		}
		else
		{
			for(int j=n;j>=1;j--)
			{
				if(a[c]==r)
				{
					cout<<i<<' '<<j;
					return 0;
				}
				c++;
			}
		}
	}
	return 0;
}