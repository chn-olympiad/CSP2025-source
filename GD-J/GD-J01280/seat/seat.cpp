#include<bits/stdc++.h>
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
	int s=a[1];
	sort(a+1,a+1+n*m);
	int x=1,y=1;
	for(int i=n*m;i>=1;i--)
	{
		if(a[i]==s)
		{
			cout<<x<<' '<<y;
			return 0;
		}
		else if(x%2==1)
		{
			if(y==n)
			{
				x++;
			}
			else
			{
				y++;
			}
		}
		else
		{
			if(y==1)
			{
				x++;
			}
			else
			{
				y--;
			}
		}
	}
	return 0;
}
