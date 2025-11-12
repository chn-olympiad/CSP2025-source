#include<bits/stdc++.h>
using namespace std;
int n,m,a[200],sum=1,x,y;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	for(int i=2;i<=n*m;i++)
	{
		if(a[1]<a[i])
		{
			sum++;
		}
	}
	x=(sum+n-1)/n;
	if(x%2==1)
	{
		y=(sum-1)%n+1;
	}
	else
	{
		y=n-((sum-1)%n+1)+1;
	}
	cout<<x<<' '<<y;
	return 0;
}
