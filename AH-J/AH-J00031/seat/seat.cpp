#include<bits/stdc++.h>
using namespace std;
long long n,m,k,x=1,y=1,f;
long long a[105];
long long cmp(int x,int y)
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
	k=a[1];
	sort(a+1,a+n*m+1,cmp);
	if(a[1]==k)
	{
		cout<<y<<" "<<x;
		return 0;
	}
	for(int i=2;i<=n*m;i++)
	{
		if(f==0)
		{
			if(y%2==1)
			{
				x++;
			}
			else
			{
				x--;
			}
		}
		else
		{
			f=0;
			if(a[i]==k)
			{
				cout<<y<<" "<<x;
				return 0;
			}
			continue;
		}
		if(a[i]==k)
		{
			cout<<y<<" "<<x;
			return 0;
		}
		if(x==n||x==1)
		{
			y++;
			f=1;
		}
	}
}
