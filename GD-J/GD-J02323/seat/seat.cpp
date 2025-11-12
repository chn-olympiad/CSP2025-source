#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int t=a[1];
	sort(a+1,a+1+n*m,cmp);
	int x=0,y=1;
	for(int i=1;i<=n*m;i++)
	{
		if(y%2==1)
		{
			x++;
			if(x==n+1)
			{
				x=n;y++;
			}
		}
		else
		{
			x--;
			if(x==0)
			{
				x=1;y++;
			}
		}
		if(a[i]==t)
		{
			cout<<y<<" "<<x;
			return 0;	
		}
	}
	return 0;
}
