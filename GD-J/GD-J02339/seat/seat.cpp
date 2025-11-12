#include<bits/stdc++.h>
using namespace std;
int main()
{	int n,m;
	freopen("seat.in","r",stdin);
	
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int a1;
	cin>>a1;
	int max1=a1;
	for(int i=0;i<n;i++)
	{for(int j=0;j<m;j++)
	{if(!(i==0&&j==0))
	{
	int s;
	cin>>s;
	max1=max(max1,s);
	}
	}
	}	
	int y=(max1-a1)/n+1;
	int x;
	if(((max1-a1)/n)%2==0)
	{x=(max1-a1)%n+1;
	}
	else
	{
	x=n-(max1-a1)%n;	
	}
	cout<<y<<' '<<x;
}
