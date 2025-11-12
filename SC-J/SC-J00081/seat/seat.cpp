#include<bits/stdc++.h>
using namespace std;
int n,m,l,r,cnt=1,a[105];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
		if(a[i]>a[1])
		{
			cnt++;
		}
	}
	if(cnt%n==0)
	{
		l=cnt/n;
		if(l%2==0)
		{
			r=1;	
		}
		else
		{
			r=n;
		}
	}
	else
	{
		l=cnt/n+1;
		if(l%2==0)
		{
			r=n-cnt%n+1;
		}
		else
		{
			r=cnt%n;
		}
	}
	cout<<l<<" "<<r;
	return 0;
}