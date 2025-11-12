#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int maxx=0;
	int m,n;
	cin>>n>>m;
	int sum=n*m;
	int seat[105],a[105]={0};
	for(int i=1;i<=sum;i++)
	{
		cin>>seat[i];
		if(seat[i]>maxx)
		{
			maxx=seat[i];
		}
		a[seat[i]]++;
	}
	int ans=0;
	for(int i=maxx;i>=0;i--)
	{
		if(a[i]>0&&i>seat[1])
		{
			ans+=a[i];
		}
		else if(i==seat[1])
		{
			int lie=ans/n+1;
			cout<<lie<<" ";
			if(lie%2==1)
			{
				cout<<ans%n+1;
				return 0;
			}
			else if(lie%2==0)
			{
				cout<<n-ans%n;
				return 0;
			}
		}
	}
	return 0;
}
