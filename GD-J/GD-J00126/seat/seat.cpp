#include<bits/stdc++.h>
using namespace std;
int n,m,x,v,c,r,u;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>x;
		if(i==1)
		{
			v=x;
		}
		else
		{
			if(x>v)
			{
				u++;
			}
		}
	}
	u++;
//	cout<<u<<endl;
	if(u%n==0)
	{
		c=u/n;
		if(c%2==0)
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
		c=u/n+1;
		if(c%2==0)
		{
			r=u%n;
			r=n-r+1;
		}
		else
		{
			r=u%n;
		}
	}
	cout<<c<<" "<<r;
	return 0;
} 
/*
3 3
94 95 96 97 98 99 100 93 92

*/
