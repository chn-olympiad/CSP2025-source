#include<bits/stdc++.h>
using namespace std;
int n,m,a[105];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int X=n*m;
	for(int i=1;i<=X;i++)
	{
		cin>>a[i];
	}
	int R=a[1];
	sort(a+1,a+X+1,cmp);
	int p;
	for(int i=1;i<=X;i++)
	{
		if(a[i]==R)
		{
			p=i;
			break;
		}
	}
	int x=1,y=1,d=0;
	for(int i=1;i<p;i++)
	{
		if(y==n&&d==0)
		{
			x++;
			d=1;
		}
		else if(y==1&&d==1)
		{
			x++;
			d=0;
		}
		else
		{
			if(d==0)y++;
			else y--;
		}
	}
	cout<<x<<" "<<y;
	return 0;
}