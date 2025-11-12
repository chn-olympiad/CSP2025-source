#include <bits/stdc++.h>
using namespace std;
int a[105],n,m,f,o;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	f=a[1];
	sort(a,a+n*m+1);
	for(int i=n*m;i>=1;i--)
	{
		if(a[i]==f)
		{
			o=n*m-i+1;
		}
	}
	if(o%n==0)
	{
		cout<<o/n<<" ";
		if((o/n)%2==1)
		{
			cout<<n;
		}
		else
		{
			cout<<"1";
		}
	}
	else
	{
		cout<<o/n+1<<" ";
		if((o/n+1)%2==0)
		{
			cout<<n-o%n+1;
		}
		else
		{
			cout<<o%n;
		}
	}
}
