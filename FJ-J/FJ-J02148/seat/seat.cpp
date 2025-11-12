#include<bits/stdc++.h>
using namespace std;
int n,m,t,a[105];
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
		if(i==1)
		{
			t=a[i];
		}
	}
	sort(a+1,a+m*n+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==t)
		{
			t=i;
		}
	}
	if(t<=n)
	{
		if(t%n==0)
		{
			cout<<"1 "<<n;
		}
		else
		{
			cout<<"1 "<<t%n;
		}
	}
	else
	{
		if(t==n*m)
		{
			cout<<m<<" "<<n;
			return 0;
		}
		if((t/n+1)%2==0)
		{
			if(t%n==0)
			{
				cout<<t/n+1<<" 1";
			}
			else
			{
				cout<<t/n+1<<" "<<n-t%n+1;
			}
		}
		else
		{
		    if(t%n==0)
			{
				cout<<t/n+1<<" "<<n;
			}
			else
			{
				cout<<t/n+1<<" "<<t%n;
			}
		}
	}
	return 0;
}
