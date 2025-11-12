#include<bits/stdc++.h>
using namespace std;
int b[10000];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n=0;
    int m=0;
    int c,r,d,j=0;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
		cin>>b[i];
	}
	d=b[1];
	for(int i=1;i<=n*m;i++)
	{
		if(b[i]>=d)
		{
			j++;
		}
	}
	c=j/n;
	if(j%n!=0)
	{
		c++;
		if(c%2==0)
		{
			r=n-(j%n-1);
		}
		else if(c%2!=0)
		{
			r=j%n;
		}
	}
	else if(j%n==0)
	{
		r=n;
	}
	cout<<c<<" "<<r;
    return 0;
}


