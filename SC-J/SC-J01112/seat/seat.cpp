#include <bits/stdc++.h>
using namespace std;
int a[10005],sum=1,v=1,m,n;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m*n;i++)
	{
		cin>>a[i];
		if(a[i]>a[1])
		{
			sum++;
		}
	}
	if((sum/n)%2==1)
	{
		if(sum%n==0)
		{
			cout<<sum/n<<" "<<n;
		}
		else
		{
			cout<<sum/n+1<<" "<<n-sum%n+1;
		}
	}
	else
	{
		if(sum%n==0)
		{
			cout<<sum/n<<" "<<1;
		}
		else
		{
			cout<<sum/n+1<<" "<<sum%n;
		}
	}
    return 0;
}