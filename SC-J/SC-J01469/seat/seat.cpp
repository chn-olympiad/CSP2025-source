#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[11000],b[110][110],k;
bool cmp(int x,int y)
{
	if(x>y)
	{
		return true;
	}
	else 
	{
		return false;
	}
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
	k=a[1];
	sort(a+1,a+(n*m+1),cmp);
	int x=1,y=1;
//	for(int i=1;i<=n*m;i++)
//	{
//		cout<<a[i]<<endl;
//	}
	for(int i=1;i<=n*m;i++)
	{
		if(y%2==1)
		{
			b[x][y]=a[i];
			if(b[x][y]==k)
			{
				cout<<y<<" "<<x<<endl;
			}
			x++;
		}
		if(y%2==0)
		{
			b[x][y]=a[i];
			if(b[x][y]==k)
			{
				cout<<y<<" "<<x<<endl;
			}
			x--;
		}
		if(x>n)
		{
			y++;
			x=n;
		}
		if(x<1)
		{
			y++;
			x=1;
		}
	}
	return 0;
}