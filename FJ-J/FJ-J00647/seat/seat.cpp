#include<bits/stdc++.h>
using namespace std;
int n,m,r;
int a[105];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==r)
		{
			r=n*m-i+1;
			break;
		}
	}
	if(r%n==0)
	{
		if((r/n)%2==1)
		{
			cout<<r/n<<" "<<n;
		}
		else if((r/n)%2==0)
		{
			cout<<r/n<<" "<<1;
		}
	}
	else if(r/n==0)
	{
		cout<<1<<" "<<r;
	}
	else if(r/n>=1)
	{
		if((r/n+1)%2==1)
		{
			cout<<r/n+1<<" "<<r%n;
		}
		else if((r/n+1)%2==0)
		{
			cout<<r/n+1<<" "<<n-r%n+1;
		}
	}
	return 0;
}
