#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[400];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int x;
	int sum=1;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
		if(i==1)x=a[i];
		else if(a[i]>x)sum++;
	}
	if(sum%n==0)
	{
		if(sum%(2*n)==0)
		{
			cout<<sum/n<<" "<<1;
		}
		else
		{
			cout<<sum/n<<" "<<n;
		}
	}
	else
	{
		if(sum%(2*n)<=n)
		{
			cout<<sum/n+1<<" "<<sum%n;
		}
		else
		{
			cout<<sum/n+1<<" "<<n-sum%n+1;
		}
	}
	return 0;
}
