#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int r;
	cin>>r;
	int sum=1;
	for(int i=2;i<=n*m;i++)
	{
		int x;
		cin>>x;
		if(x>r)sum++;
	}
	int x=0,y=0;
	if(sum%n!=0)
	{
		x=sum/n+1;
		if(x%2==0)
		{
			y=n-(sum%n)+1;
		}
		else y=(sum%n);
	}
	else
	{
		x=sum/n;
		if(x%2==0)
		{
			y=1;
		}
		else y=n;
	} 
	cout<<x<<' '<<y;
	return 0;
}
