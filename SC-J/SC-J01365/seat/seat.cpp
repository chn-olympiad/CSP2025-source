#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int id,nmax=1;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
		id=a[1];
		if(id<a[i])nmax++;
	}
	int sum=nmax/n,res=nmax%n;
	if(sum%2==1)
	{
		if(res==0)
		{
			cout<<sum<<" "<<n;
			return 0;
		}
		cout<<sum+1<<" "<<n-res+1;
		return 0;
	}
	else
	{
		if(res==0)
		{
			cout<<sum<<" "<<"1";
			return 0;
		}
		cout<<sum+1<<" "<<res;
	}
	return 0;
}