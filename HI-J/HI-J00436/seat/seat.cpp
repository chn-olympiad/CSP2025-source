#include<bits/stdc++.h>
using namespace std;
int a[105];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,c;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	c=a[1];
	sort(a,a+n*m+1);
	int d=n*m,f=0;
	for(int i=1;i<=m;i++)
	{
		if(i%2==1)
		{
			for(int j=1;j<=n;j++)
			{
				if(a[d]==c)
				{
					cout<<i<<" "<<j<<endl;
					f=1;
				}
				d--;
			}
		}
		else
		{
			for(int j=n;j>=1;j--)
			{
				if(a[d]==c)
				{
					cout<<i<<" "<<j<<endl;
					f=1;
				}
				d--;
			}
		}
		if(f==1)
		{
			break;
		}
	}
	return 0;
}
