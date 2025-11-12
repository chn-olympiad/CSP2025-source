#include<bits/stdc++.h>
using namespace std;
long long n,m,a[105],R,ans;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	R=a[1];
	sort(a+1,a+n*m+1,greater<long long>());
	for(int i=1;i<=n*m;i++)
	{
		if(R==a[i])
		{
			ans=i;
			break;
		}
	}
	if(ans%n==0)
	{
		if((ans/n)%2==0)
		{
			cout<<ans/n<<" "<<1;
		}
		else
		{
			cout<<ans/n<<" "<<n;
		}
	}
	else
	{
		int t=ans/n+1;
		cout<<t<<" ";
		t=ans%n;
		if((ans/n+1)%2==0)
		{
			cout<<n-t+1;
		}
		else
		{
			cout<<t;
		}
	}
}
