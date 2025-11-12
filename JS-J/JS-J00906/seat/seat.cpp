#include<bits/stdc++.h>
using namespace std;

int n,m,a[110],x,ans;

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	x=a[1];
	sort(a+1,(n*m)+a+1);
	ans=find(a+1,(n*m)+a+1,x)-a;
	ans=n*m-ans+1;
	if(ans%n!=0)
	{
		if((ans/n+1)%2==0)
			cout<<ans/n+1<<' '<<n-ans%n+1;
		else
			cout<<ans/n+1<<' '<<ans%n;
	}
		
	else
	{
		if((ans/n+1)%2==0)
			cout<<ans/n<<' '<<n;
		else
			cout<<ans/n<<' '<<1;
	}
	return 0;
}
