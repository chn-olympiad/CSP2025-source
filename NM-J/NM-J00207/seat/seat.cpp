#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r"std.in);
	freopen("seat.out","w"std.out);
	int n,m,a[1000],c=1,d=1;
	cin>>n>>m;
	for(int i=0;i<n*m;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n*m;i++)
	{
		if(a[0]<a[i])
		{
			c=c+1;
			if(c>n)
			{
				c=1;
				d=d+1;
			}
			
		}
	}
	cout<<d<<" "<<c;
	
	return 0;
}
