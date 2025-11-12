#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m,a[105],a1,ans=1;
	cin>>n>>m;
	for(int i = 1;i<=n*m;i++)
	{
		cin>>a[i];
		if(i==1)
		{
			a1=a[i];
		}
		else
		{
			if(a[i]>a1)
			{
				ans++;
			}
		}
	}
	if(ans%n==0)
	{
		if((ans/n)%2==0)
		{
			cout<<ans/n<<' '<<1;
		}
		else
		{
			cout<<ans/n<<' '<<n;
		}
	}
	else
	{
		if((ans/n)%2==0)
		{
			cout<<ans/n+1<<' '<<ans%n;
		}
		else
		{
			cout<<ans/n+1<<' '<<n-(ans%n)+1;
		}
	}
	return 0;
}
