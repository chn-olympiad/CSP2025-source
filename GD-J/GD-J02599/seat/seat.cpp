#include <bits/stdc++.h>
using namespace std;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[105];
	for (int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int sum=a[1],b=0;
	sort(a+1,a+n*m+1,cmp);
	for (int i=1;i<=n*m;i++)
	{
		if (a[i]==sum)
		{
			b=i;
			break;
		}
	}
	if (b<=n && m==1)
	{
		cout<<1<<" "<<b;
	}
	else if (n==1)
	{
		cout<<b<<" "<<1;
	}
	else if (b%n==0)
	{
		if ((b/n)%2==0)
		{
			cout<<b/n<<" "<<1;
		}
		else
		{
			cout<<b/n<<" "<<n;
		} 
	}
	else if ((b-1)%n==0)
	{
		if (((b-1)%n)%2==0)
		{
			cout<<b/n+1<<" "<<1;
		}
		else
		{
			cout<<b/n+1<<" "<<n;
		}
	}
	else if (b==(a[1]+a[n*m])/2)
	{
		cout<<m/2+1<<" "<<n/2+1;
	}
	else
	{
		cout<<b/n+1<<" "<<m%b;
	}
	return 0;	
} 
