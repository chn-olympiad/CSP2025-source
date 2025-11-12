#include <bits/stdc++.h>
using namespace std;
int n,m,a[105],t;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	t=a[1];
	for(int i=1;i<=n*m;i++)
	{
		for(int j=i+1;j<=n*m;j++)
		{
			if(a[i]<a[j])
			{
				int s=a[i];
				a[i]=a[j];
				a[j]=s;
			}
		}
	}
	for(int i=1;i<=n*m;i++)
	{
		if(t==a[i])
		{
			t=i;
			break;
		}
	}
	if(t%n==0)
	{
		cout<<t/n<<" ";
		if((t/n)%2==0)
		{
			cout<<1;
		}
		else
		{
			cout<<n;
		}
	}
	else
	{
		cout<<t/n+1<<" ";
		if((t/n+1)%2==0)
		{
			cout<<(n-(t-(n*(t/n))))+1;
		}
		else
		{
			cout<<t-(n*(t/n));
		}
	}
	return 0;
}

