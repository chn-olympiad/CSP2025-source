#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a1,sum=0;
	cin>>a1;
	for(int i=2;i<=n*m;i++)
	{
		int w;
		cin>>w;
		if(w>a1)
		{
			sum++;
		}
	}
	sum++;
	int ans1=sum/n,ans2=sum%n;
	if(ans1%2==0)
	{
		if(ans2==0)
		cout<<ans1<<' '<<'1';
		else
		cout<<ans1+1<<' '<<ans2;
	}
	else
	{
		if(ans2==0)
		cout<<ans1<<' '<<n;
		else
		cout<<ans1+1<<' '<<n-ans2+1;
	}
	return 0;
}
