#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a=n*m;
	int b[a+1];
	int c;
	for(int i=1;i<=a;i++)
    {
	    cin>>b[i];
	    c=b[1];
    }
    for(int i=1;i<=a;i++)
    {
    	for(int j=i+1;j<=a;j++)
    	{
    		if(b[j]>b[i])
    		{
    			int temp=b[i];
    			b[i]=b[j];
    			b[j]=temp;
			}
		}
	}
	int d=0;
	for(int i=1;i<=a;i++)
	{
		if(b[i]==c)
		{
			d=i;
		}
	}
	int x=0;
	if(d%n==0)
	{
	    x=d/n;
	}
	else
	{
		x=d/n+1;
	}
	int q=d%n;
	int y=0;
	if(x%2==0)
	{
		if(q==n)
		{
			y=1;
		}
		else
		{
			y=m-q+1;
		}
	}
	else
	{
		if(q==0)
		{
			y=n;
		}
		else
		{
			y=q;
		}
	}
	cout<<x<<" "<<y<<endl;
	return 0;
}
