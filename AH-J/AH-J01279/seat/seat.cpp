#include<bits/stdc++.h>
using namespace std;
long long a[105];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long i,n,m,t,c;
	cin>>n>>m;
	for(i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	t=a[1];
	sort(a+1,a+n*m+1);
	for(i=1;i<=n*m;i++)
	{
		if(a[i]==t)
		{
			c=n*m-i+1;
			break;
		}
	}
	cout<<c<<" ";
	if(c%n==0)
	{
		if((c/n)%2!=0)
			cout<<c/n<<" "<<n;
		else
			cout<<c/n<<" "<<1;
	}
	else
	{
		if((c/n+1)!=0)
			cout<<c/n+1<<" "<<c%n;
		else
			cout<<c/n+1<<" "<<n-c%n+1;
	}
}
